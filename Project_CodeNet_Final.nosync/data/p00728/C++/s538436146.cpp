#include <queue>//priority_queue
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <array>
#include <map>
#include <list>
#include <set>
#include <utility>
#include <vector>
#include <cmath>
#include <bitset>
#include <iostream>

#pragma warning(disable: 4996)

/*-------マクロ定義---------*/

#define REP(i , n) for(L i = 0 ; i < n ; i++)
#define TIMES(n) REP(i , n)


/*---------Typedef------------*/

//long
typedef long L;
typedef std::pair<L, L>				IntPair;
typedef std::vector<L>				IntVector;
typedef std::priority_queue<L>		IntPriority;
typedef std::queue<L>				IntQueue;
typedef std::stack<L>				IntStack;

//unsigned long
typedef unsigned long ul;
typedef std::pair<ul, ul>			UIntPair;
typedef std::vector<ul>				UIntVector;
typedef std::priority_queue<ul>		UIntPriority;
typedef std::queue<ul>				UIntQueue;
typedef std::stack<ul>				UIntStack;

//double
typedef double D;
typedef std::pair<D, D>				DoublePair;
typedef std::vector<D>				DoubleVector;
typedef std::priority_queue<D>		DoublePriority;
typedef std::queue<D>				DoubleQueue;
typedef std::stack<D>				DoubleStack;

//char
typedef char Ch;
typedef std::pair<Ch, Ch>			CharPair;
typedef std::vector<Ch>				CharVector;
typedef std::priority_queue<Ch>		CharPriority;
typedef std::queue<Ch>				CharQueue;
typedef std::stack<Ch>				CharStack;

//
/*  VectorArray	Dp(1000,IntVector(1000)); */
typedef std::vector<std::vector<L>>		VectorArray;
typedef std::vector<std::vector<ul>>	UVectorArray;
typedef std::vector<std::vector<D>>		DVectorArray;


/*--------ScanOverLoad----------*/

//type long//

void Scan(L& output)
{
	scanf("%ld", &output);
}

void Scan(IntVector& vector)
{
	L scan = 0;
	scanf("%ld", &scan);
	vector.push_back(scan);
}

void Scan(IntPriority& pri_que)
{
	L scan = 0;
	scanf("%ld", &scan);
	pri_que.push(scan);
}

void Scan(IntQueue& que)
{
	L scan = 0;
	scanf("%ld", &scan);
	que.push(scan);
}

void Scan(IntStack& stack)
{
	L scan = 0;
	scanf("%ld",&scan);
	stack.push(scan);
}

//type unsigned long//

void Scan(ul& output)
{
	scanf("%lu", &output);
}

void Scan(UIntVector& vector)
{
	ul scan = 0;
	scanf("%lu", &scan);
	vector.push_back(scan);
}

void Scan(UIntPriority& pri_que)
{
	ul scan = 0;
	scanf("%lu", &scan);
	pri_que.push(scan);
}

void Scan(UIntQueue& que)
{
	ul scan = 0;
	scanf("%lu", &scan);
	que.push(scan);
}

void Scan(UIntStack& stack)
{
	ul scan = 0;
	scanf("%lu", &scan);
	stack.push(scan);
}

//type double//

void Scan(D& output)
{
	scanf("%lf", &output);
}

void Scan(DoubleVector& vector)
{
	D scan = 0;
	scanf("lf", &scan);
	vector.push_back(scan);
}

void Scan(DoublePriority& pri_que)
{
	D scan = 0;
	scanf("%lf", &scan);
	pri_que.push(scan);
}

void Scan(DoubleQueue& que)
{
	D scan = 0;
	scanf("%lf", &scan);
	que.push(scan);
}

void Scan(DoubleStack& stack)
{
	D scan = 0;
	scanf("%lf", &scan);
	stack.push(scan);
}

//type char//

void Scan(Ch& output)
{
	scanf("%c", &output);
}

void Scan(CharVector& vector)
{
	Ch scan = 0;
	scanf("%c", &scan);
	vector.push_back(scan);
}

void Scan(CharPriority& pri_que)
{
	Ch scan = 0;
	scanf("%c", &scan);
	pri_que.push(scan);
}

void Scan(CharQueue& que)
{
	Ch scan = 0;
	scanf("%c", &scan);
	que.push(scan);
}

void Scan(CharStack& stack)
{
	Ch scan = 0;
	scanf("%c", &scan);
	stack.push(scan);
}

/*----------Print----------*/

struct OPrint{
	void operator()(L& value)		{ printf("%ld", value); }
	void operator()(ul& value)		{ printf("%lu", value); }
	void operator()(D& value)		{ printf("%lf", value); }
	void operator()(Ch& value)		{ printf("%c", value); }
};

template<class T>
void Print(T& value){ std::for_each(value.begin(), value.end(), OPrint()); }

void Print(L value){ printf("%ld", value); }

void Print(ul value){ printf("%lu", value); }

void Print(D value){ printf("%lf", value); }

void Print(Ch value){ printf("%c", value); }

/*----------Init---------*/

template<class T>
struct OInit{
	T x;

	OInit(T _x) :x(_x){}

	void operator()(L& value)	{ value = x; }
	void operator()(ul& value)	{ value = x; }
	void operator()(D& value)	{ value = x; }
	void operator()(Ch& value)	{ value = x; }
};

template<class T1 , class T2>
void Init(T1& value,T2 x){ std::for_each(value.begin(), value.end(), OInit<T2>(x)); }

void Init(L& value, L x){ value = x; }

void Init(ul& value, ul x){ value = x; }

void Init(D& value, D x){ value = x; }

void Init(Ch& value, Ch x){ value = x; }



int main()
{
	for (;;){
		IntVector Point;
		L n; Scan(n);
		if (!n) return 0;

		TIMES(n)
			Scan(Point);
		std::sort(Point.begin() , Point.end());
		
		L souwa = 0;

		std::for_each(Point.begin() + 1, Point.end() - 1, [&souwa](L x){
			souwa += x;
		});
			Print(souwa / (Point.size()-2));
			puts("");
	}

	return 0;
}