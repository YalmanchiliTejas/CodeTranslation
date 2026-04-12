#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int a,b;
	scanf("%d",&a);
	int n=a*800;
	int m=n-a/15*200;
	printf("%d\n",m);
	return 0;
}