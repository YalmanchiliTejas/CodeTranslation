#include<stdio.h>
int main()
{
	int r, g, b, sum;
	scanf("%d %d %d",&r,&g,&b);
	sum = 2*g + b;
	if (sum % 4 == 0) printf("YES");
	else printf ("NO");
	return 0;
}