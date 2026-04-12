#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int X,Y,Z;
	int sum;
	scanf("%d %d %d",&X,&Y,&Z);
	sum=(X-Z)/(Y+Z);
	printf("%d\n",sum);
	return 0;
}
