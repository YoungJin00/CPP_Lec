#define ON_MAIN
#ifdef ON_MAIN

#include <STDIO.H>//C header
#include <iostream> //C++ header

using namespace std;

class Animal
{
public:
	//1.�Ϲ� ����Լ�(���� ���ε�)
	//void Cry() { cout << "���" << endl; }
	
	//2.���� ����Լ�(���� ���ε�)
	//virtual void Cry() { cout << "���" << endl; }

	//3.���� �����Լ�
	virtual void Cry() = 0; //�������̽� ���
	
};
class Dog : public Animal
{
public:
	void Cry() { cout << "�۸۸�" << endl; }
};
class Cat : public Animal
{
public:
	void Cry() { cout << "�߿˾߿�" << endl; }
};

int main()
{
	//Upcasting & Downcating
	if (0)
	{
		class Animal
		{
		public:
			string name;
			int age;
		};
		class Dog : public Animal
		{
		public:
			int color;
		};
		Dog dog;
		dog.name = "�ܶ�";
		dog.age = 6;
		dog.color = 10;

		Animal ani;
		ani.name = "�Ŀ���";


		Dog* p = &dog;
		p = &dog;

		Animal* p2;
		p2 = &dog;
		p2 = &ani;

		//1.upcasting(������)
		// ���� �����ʹ� �ٸ� Ÿ���� �ּҸ� ���� �� ����.
		//������ �θ� �����ʹ� �ڽ��� �ּҸ� ���� ���ִ�(=upcasting)
		int a = 10;
		//int* p = &a;
		Animal* pAni = &dog;
		pAni->age = 7;

		//2.downcasting(������)
		//Dog* pDog = pAni;
		Dog* pDog = (Dog*)pAni;//downcasting�� ���� ����ȯ�ؾ���
		pDog->age = 8;
		pDog->color = 20;


	
	}

	//�Լ� �������̵� + �����Լ�(virtual)
	if (0)
	{
		///////////////////////
		//������
		Dog d;
		d.Cry();

		Cat c;
		c.Cry();


		/// /////////////////////
		Animal* p;
		p = &d;
		p->Cry();

		p = &c;
		p->Cry();

		//////////////////////
		//Animal a; //���� ����Ŭ������ ��ü�� ���� �� ����.

	}


	//���� �Ҹ���
	if (1)
	{
		class Base
		{
		public:
			Base() { cout << "Base()" << endl; }
			~Base() { cout << "~Base()" << endl; }
		};
		class Derived : public Base
		{
		public:
			Derived()
			{
				cout << "Derived() - �ڿ�ȹ��" << endl;
				pData1 = new int;
				pData2 = new int[20];
			}
			~Derived()
			{
				cout << "~Derived() - �ڿ��ݳ�" << endl;
				delete pData1;
				delete[] pData2;

			}
			int* pData1;
			int* pData2;
		};
		//Derived x;

		Base* p = new Derived;
		delete p;
	}
	return 0;
}
#endif