#include<cstdio>


int main(void)
{
	int x;
	int ans=0;

	scanf("%d", &x);

	if(x==7 || x==5 || x==3) ans=1;

	printf("%s\n", ans?"YES":"NO");

	return 0;
}
