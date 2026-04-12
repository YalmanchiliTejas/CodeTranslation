#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
	int a,b,c,d;
	scanf("%d %d %d",&a,&b,&c);
    d=(a-c)/(b+c);
    printf("%d\n",d);
	return 0;
}