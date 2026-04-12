#include<cstdio>


int main(void)
{
	int r, g, b;

	while(scanf("%d%d%d", &r, &g, &b)==3)
	{
		printf("%s\n", ((g*10+b)%4==0)?"YES":"NO");
	}

	return 0;
}
