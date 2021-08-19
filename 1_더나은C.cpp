//#define ON_MAIN
#ifdef ON_MAIN

#include <STDIO.H> //C header
#include <iostream> //C++ header

using namespace std;

int g_nData = 10;
void Gugudan(void)
{
	std::cout << "Global::Gugudan()" << endl;
}

namespace TEST
{
	int g_nData = 100;
	void Gugudan(void)
	{
		std::cout << "Global::Gugudan()" << endl;
	}
}
void Swap(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;

	cout << "SWAP : " << "a=" << a << " b=" << b << endl;
}

void Swap2(int* a, int* b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

	cout << "SWAP2 : " << "a=" << *a << " b=" << *b << endl;
}
void Swap3(int& a, int& b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;

	cout << "SWAP3 : " << "a=" << a << " b=" << b << endl;
}


int Sum(int a, int b)
{
	cout << "Sum(int a, int b)" << endl;
	return a + b;
}

int Sum(int a, int b, int c)
{
	cout << "Sum(int a,int b,int c)" << endl;
	return a + b + c;
}

int Sum(double a, double b)
{
	cout << "Sum(double a, double b)" << endl;
	return a + b;
}

int TestFunc(int a = 10)
{
	return a;
}

int TestFunc2(int a ,int b = 20 , int c =30)
{
	return a+b+c;
}

#define ADD(a,b) (a +b) //매크로 (C제공)


int Add(int a, int b)
{
	return a + b;
}

inline AddNew(int a, int b)
{
	return a + b;
}
int main() 
{
	//cout 객체
	if (0) {
	printf("Hello World, 영진\n");
	std::cout << "Hello World, 영진\n";

	int a = 10;
	int b = 20;

	

	//a=10,b=20
	printf("a=%d, b=%d\n", a, b);
	std::cout << "a=" << a << " b=" << b << "\n";


	std::cout << a << std::endl;
	std::cout << &a << std::endl;
	std::cout << sizeof(a) << std::endl;

	std::cout << printf << std::endl;
	std::cout << main << std::endl;

	cout << "BYE" << "\n";
	}


	if (0)
	{
		int nAge;
		cout << "나이를 입력하세요 : " << endl;
		cin >> nAge;
		//scanf("%d",&nAge);

		std::string strName;
		cout << "이름을 입력하세요 : " << endl;
		cin >> strName;

		char strJob[30];
		cout << "직업을 입력하세요 : " << endl;
		cin >> strJob;

		cout << "나이 : " << nAge << endl;
		cout << "이름 : " << strName << endl;
		cout << "직업 : " << strJob << endl;
	}
	//auto
	if (0) {
		int a = 10;
		int b(a);
		auto c(a); // 위에 a값들가 자동으로 같은 변수로 출력

		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
	}

	//네임스페이스
	if (0)
	{
		::Gugudan();
		TEST::Gugudan();

	}

	//Pointer(C) VS Reference(CPP)
	if (0)
	{
		int a = 10;
		int* p1 = &a;

		cout << sizeof(a) << endl;
		cout << sizeof(p1) << endl;

		char b = 'a';
		char* p2 = &b;

		cout << sizeof(b) << endl;
		cout << sizeof(p2) << endl;

		//Reference(CPP)----------------
		int nData = 10;
		int& ref = nData; //레퍼런스(별명)

		nData++; //11
		cout << nData << endl;
		cout << ref << endl;

		ref++;
		cout << nData << endl;
		cout << ref << endl;

	}
	//함수 호출 방식
	if (0)
	{
		int a = 10;
		int b = 20;
		cout << "a=" << a << " b=" << b << endl;


		//C방식
		//1) Call by Value(값의 복사) >> 사용쉽다. 영향을 받지 않음
		a = 10, b = 20;
		Swap(a, b);
		cout << "a=" << a << " b=" << b << endl;
		//2) Call by Address(주소의 전달) >> 사용 어렵다. 영향을 받음
		a = 10, b = 20;
		Swap2(&a, &b);
		cout << "a=" << a << " b=" << b << endl;
		//C++방식
		//3)Call by Reference >> 사용쉽다 영향을 받음
		a = 10, b = 20;
		Swap3(a, b);
		cout << "a=" << a << " b=" << b << endl;

	}

	//함수 오버로딩(다중정의)  --by 네임맹글링
	if (0)
	{
		cout << Sum(10, 20)  << endl;
		cout << Sum(10, 20, 30) << endl;
		cout << Sum(10.5, 20.9) << endl;
	}

	//디폴트 매개변수
	if (0)
	{
		cout << TestFunc(100) << endl;
		cout << TestFunc() << endl;

		//cout << TestFunc2() << endl;  //error
		cout << TestFunc2(1) << endl; // 1+20+30
		cout << TestFunc2(1,2) << endl; // 1+ 2+30
		cout << TestFunc2(1,2,3) << endl; //6
	}

	
	//동적메모리(C: malloc/free/ c++: new/delete)
	if (0)
	{
		int count;
		cout << "학생이 총 몇 명입니까 ? ";
		cin >> count;

		int* p = (int*)malloc(sizeof(int) * count); //int[4]
		p[0] = 10;
		*(p + 0) = 10;
		*p = 10;
		p[1] = 20;
		*(p + 1) = 20;
		*p = 20;

		p[2] = 30;
		p[3] = 40;
		free(p);

		//C++: new/delete
		int* p2 = new int;
		*p2 = 100;

		int* p3 = new int(10); //초기값10할당함

		cout << *p2 << endl;
		cout << *p3 << endl;

		delete p2;
		delete p3;

		//배열
		int* p4 = new int[5];
		for (int i = 0; i < 5; i++)
		{
			p4[i] = i * 10;
			cout << p4[i] << endl;
		}
		delete[] p4;
	}

	//범위기반 for문
	if (0)
	{
		//int aList[5] = { 10, 20, 30, 40, 50 };
		int aList[5] = { 0, };
		for (int i = 0; i < 5; i++)
		{
			cout << aList[i] << endl;
		}
		//범위 기반 for문
		for (auto x : aList) //복사
		{
			cout << x << endl;
		}
		cout << endl;
		for (auto& x : aList) //참조(=별명)(복사X)
		{
			cout << x << endl;
		}
	}

	//인라인 함수
	if (1)
	{
		int a = 10;
		int b = 20;

		cout << ADD(a, b) << endl; //매크로(C제공)
		cout << Add(a, b) << endl;//함수 호출(C제공)
		cout << AddNew(a, b) << endl; //인라인함수 호출(C++)
	}
	return 0; // 정상종료
}

#endif