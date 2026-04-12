#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,y,m;
int main()
{
	scanf("%d",&n);
	x=n*800;
	y=n/15*200;
	m=x-y;
	printf("%d\n",m);
	return 0;
}