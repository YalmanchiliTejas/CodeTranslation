#include<stdio.h>
int main()
{
	int a,b,d;
	scanf("%d %d %d",&a,&b,&d);
	if(!((b*10+d)%4))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}