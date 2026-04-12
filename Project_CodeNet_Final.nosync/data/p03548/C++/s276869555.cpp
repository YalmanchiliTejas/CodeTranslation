#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a,b,c,s=0;
	scanf("%d %d %d",&a,&b,&c);
	s=(a-c)/(b+c);
	printf("%d\n",s);
	return 0;
}