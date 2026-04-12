#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	x-=z;
	x=x/(y+z);
	printf("%d",x);
	return 0;
}