#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
	int X,Y,Z;
	int N;
	scanf("%d %d %d",&X,&Y,&Z);
	N=(X-Z)/(Y+Z);
	printf("%d",N);
	return 0;
}