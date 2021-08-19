//#define ON_MAIN
#ifdef ON_MAIN

#include <STDIO.H>//C header
#include <iostream> //C++ header

using namespace std;

typedef struct USERDATA
{
	int nAge;
	char szName[32];

	void PrintData()
	{
		printf("%d,%s\n", nAge, szName);
	}

} USERDATA;

void PrintData(USERDATA* p)
{
	printf("%d,%s\n", p->nAge, p->szName);
}

int main()
{
	//구조체(=사용자정의 데이터 타입)
	if (0)
	{
		USERDATA kim = { 20,"김철수" };
		PrintData(&kim);
		//printf("%d,%s\n", kim.nAge, kim.szName);
	}

	//객체
	if (1)
	{
		class Human
		{
		public:
			int nAge;
			string szName;

			void PrintData()
			{
				printf("%d,%s\n", nAge, szName);
			}

		};

		Human lee = { 33,"이길동" };
		lee.PrintData();
	}
	return 0;
}


#endif
