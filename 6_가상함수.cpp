#define ON_MAIN
#ifdef ON_MAIN

#include <STDIO.H>//C header
#include <iostream> //C++ header

using namespace std;

class Animal
{
public:
	//1.일반 멤버함수(정적 바인딩)
	//void Cry() { cout << "운다" << endl; }
	
	//2.가상 멤버함수(동적 바인딩)
	//virtual void Cry() { cout << "운다" << endl; }

	//3.순수 가상함수
	virtual void Cry() = 0; //인터페이스 상속
	
};
class Dog : public Animal
{
public:
	void Cry() { cout << "멍멍멍" << endl; }
};
class Cat : public Animal
{
public:
	void Cry() { cout << "야옹야옹" << endl; }
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
		dog.name = "꿀띠";
		dog.age = 6;
		dog.color = 10;

		Animal ani;
		ani.name = "냐옹이";


		Dog* p = &dog;
		p = &dog;

		Animal* p2;
		p2 = &dog;
		p2 = &ani;

		//1.upcasting(형상향)
		// 원래 포인터는 다른 타입의 주소를 담을 수 없다.
		//하지만 부모 포인터는 자식의 주소를 담을 수있다(=upcasting)
		int a = 10;
		//int* p = &a;
		Animal* pAni = &dog;
		pAni->age = 7;

		//2.downcasting(형하향)
		//Dog* pDog = pAni;
		Dog* pDog = (Dog*)pAni;//downcasting은 강제 형변환해야함
		pDog->age = 8;
		pDog->color = 20;


	
	}

	//함수 오버라이드 + 가상함수(virtual)
	if (0)
	{
		///////////////////////
		//다형성
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
		//Animal a; //순수 가상클래스는 객체를 만들 수 없다.

	}


	//가상 소멸자
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
				cout << "Derived() - 자원획득" << endl;
				pData1 = new int;
				pData2 = new int[20];
			}
			~Derived()
			{
				cout << "~Derived() - 자원반납" << endl;
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