#include <iostream>

using namespace std;

void setPointer (int k){
    cout<<"���� � �������"<<endl;
    int* pa=&k;//����� ��������� �� ��������
    cout<<"����� ���������� k: "<<pa<<endl;
    cout<<"k= "<<k<<endl;//������� �������� ���������
    k=10;//���� ��� ����� ��������
    cout<<"k= "<<k<<endl;//������� ���
    cout<<"����� �� �������"<<endl;
}

int* getPointer(int value){
    int a=value;
    int* pa=&a;
    return pa;
}


int main()
{
    setlocale(0, "");
    cout<<"������� 1.1:\n";
    int k(9);//����� ���������� �=9
    int* pk=&k;//����� ��������� �� ����� ���������� �
    cout<<"����� ���������� k: "<<pk<<endl;
    setPointer(k);// �������� ���������� � � �������� ��������� �������
    cout<<"k= "<<k<<endl<<endl<<endl;//��������� �������� ���������� k ����� ������ �������. � ��� �������� k=9, �� � ������� �� ������ �������� k=10. ������������� ��������, ��� ���������� k (�� main) � k (�� setPointer) ��� 2 ������ ����������.

    cout<<"������� 1.2:\n";
    cout<<"�������� �� ������ ����� ������� ������ �������: ";
    int* a=getPointer(0);
    cout<<*a<<endl;
    cout<<"�������� �� ������ �� ������ ����� ������� ������ �������: ";
    getPointer(1);
    cout<<*a<<endl;

    return 0;
}
