#include<stdio.h>
int main(void)
{
	int r,g,b,v;
	scanf("%d%d%d",&r,&g,&b);
	v = g * 10 + b;
	if(v%4 == 0) printf("YES");
	else printf("NO");
	return 0;
}
