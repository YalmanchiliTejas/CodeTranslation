#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long n, x;

long long lenOfTotal[60];	//面包的总个数
long long lenOfPatty[60];	//对应肉饼的总个数

void init()

{
	lenOfTotal[0] = 1;	//面包的总个数
	lenOfPatty[0] = 1;	//对应肉饼的总个数	
	
	for (int i = 1 ; i <= 50 ; i++)
	{
		lenOfTotal[i] = lenOfTotal[i - 1] * 2 + 3;
		lenOfPatty[i] = lenOfPatty[i - 1] * 2 + 1;
	}
} 

void solve(long long &numOfPatty, long long &leftLayer, int d)
{
	if (leftLayer >= lenOfTotal[d])
	{
		leftLayer = leftLayer - lenOfTotal[d];
		numOfPatty = numOfPatty + lenOfPatty[d];
		
		return;
	}
	
	leftLayer--;	//first bun
	if (leftLayer <= 0) return;
		
	solve(numOfPatty, leftLayer, d - 1);
	if (leftLayer <= 0) return;
	
	leftLayer--;
	numOfPatty++;
	if (leftLayer <= 0) return;
	
	solve(numOfPatty, leftLayer, d - 1);
	if (leftLayer <= 0) return;
	
	leftLayer--;	//last bun
	if (leftLayer <= 0) return;
	return ;
}

int main()
{
	long long leftLayer;
	long long numOfPatty;
	init();

	scanf("%lld%lld", &n, &x);
	
	leftLayer = x;
	numOfPatty = 0;
	
	solve(numOfPatty, leftLayer, n);
	
	printf("%lld\n", numOfPatty);
	
	return 0;
}