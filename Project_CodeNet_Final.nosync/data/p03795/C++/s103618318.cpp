#include<iostream>
#include<cstdio>
using namespace std;
int n,s,m;
int main()
{
	scanf("%d",&n);
	s = n / 15;
	m = n*800-s*200;
	printf("%d",m);
	printf("\n");
	return 0;
}