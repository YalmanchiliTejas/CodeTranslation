#include<stdio.h>
int main()
{
	int r, g[2], b, sum;
	scanf("%d %d %d",&r,&g[1],&b);
	if (g[1] % 2 == 0) g[2]=0;
	else g[2]=2;
	sum = g[2] + b;
	if (sum % 4 == 0) printf("YES");
	else printf ("NO");
	return 0;
}