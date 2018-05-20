#include <cstdio>
#include <cstring>
#include <clocale>


/// ������ ������ ����� ����� �� ������, ���� �� �������� ������� ������ \n.
/// ���������� ������ � ������������ ������ � ������������ ������� (\n � ����� ������ ����).
char* ReadLongString(FILE* str)//������� � ������� ����� �����
{
    // ��������� ������ ������. ����� ������������� � 2 ���� �� ������ ��������
    // � ����� ������� ���� ������� ������ ���������, � ����� ����� ������� ��������
    int size = 3; //������ ������

    // �����
    char* buf = new char[size];

    // ����� � ������, ������� � �������� ����� ����� ������. ���������� ������ ������
    char* reading = buf;

    // ����� ����� ������. ���� � �������� � 0, �� ����� ��� �������� ���������.
    buf[size-1] = 123; //� ��������� ������ ����� ����� 123

  while(true)
    {
        // ������ ������� � ����� - �� �����, ��� �������� ���� �� readStart �� ����� ������
        fgets(reading, ( size-(reading-buf)), str); /* ������� �����, � �������� ���������� ������,
        ���������� ���������� ����� � ������� � ����� ����� � �������� ������*/

        // �����������, �� �� ��������� ��� ���� ����� ��� ���������.
        if((buf[size-1]==123)||(buf[size-2]=='/n'))
        {
            // ���� ����� �� �������, �� ������ �������� � ��� ���������.
            // ���� ��������, �� ������������� ������ - ������� ������, �� ������ ���������� � ��������
            return buf;
        }else
        {
            char* newbuf = buf;// ����� �������� ����� � 2 ���� ������
            buf = new char[size*2];
            strcpy(buf, newbuf);// ��������� � ���� ������
            delete [] newbuf; // � ������� ������ �����!!!
            reading = buf + size - 1; // �������������� �������� �����, � ������� ���������� ��������� �����
            size *= 2;
            buf[size-1]=123;
        }




        // ������ ������ ����� � �������� ������ ������ (������� � �������� �����), �.�. ������ �������� ������ ������� �������.

        // �� �������� � ����� ������ ������ ���������� ����� �����
        buf[size-1] = 123;
    }

    return buf;
}



int main()
{
    //setlocale(LC_ALL, "Russian"); // ������ ������
    printf("Input long string\n");

    // ������ ������� � �������
    char* s = ReadLongString(stdin);

    // �������. ������ ����� ������ �� ������� ������ ����������, �.�. � ������ ����� ������� ������ \n
    printf("Readed: %s\nLength=%d\n", s, strlen(s));

    // ��������� � ���� - ����� ���� ��������� ��������
    // �� �������� ����� ����� ���� ����� � Notepad++ --> ��������� --> ��������� --> OEM866
    printf("Saving it to file file.txt (encoding OEM866)\n");
    FILE* out = fopen("file.txt", "w");
    // � ������� ��������� void* ���������, ������� ������ ���������� (1) �� �������, ������� ���� �������� ���� ������� �������
    fwrite(s, 1, strlen(s), out);
    // �� �������� ������� ����!
    fclose(out);

    // ������� ������ �� ����
    delete[] s;

    printf("Load it from file.txt\n");

    // ������ ����
    FILE* in = fopen("file.txt", "r");
    char* s2 = ReadLongString(in);
    fclose(in);

    printf("Read from file: %s", s2);

    // �� �������� ���������� ������
    delete[] s2;

    return 0;
}
