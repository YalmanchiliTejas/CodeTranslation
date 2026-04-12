#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
#define ABS(x) (x>0?x:-(x))

#define INF 1000000000

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int gcd(int a, int b)
{
	if (a < b)
		swap(&a, &b);

	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	int N;
	int M;
	int a[100000];
	int ans = 0;

	scanf("%d%d",&N,&M);

	if (N == M)
		printf("Yes\n");
	else
		printf("No\n");
	//printf("%d\n",ans);
}