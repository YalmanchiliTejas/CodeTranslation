#include <stdio.h>
int main()
{
	int r,g,b, n;
	scanf("%d %d %d", &r, &g, &b);
	n=r*100+g*10+b;
	if(n%4) printf("NO");
	else printf("YES");
}