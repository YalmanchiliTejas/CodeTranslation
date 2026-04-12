#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	x=x-z;
	printf("%d\n",x/(y+z));
	return 0;
}