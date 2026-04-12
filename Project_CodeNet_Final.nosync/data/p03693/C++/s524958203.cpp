# include<cstdio>

int main(void)
{
	int r, g, b;
	while(scanf("%d%d%d", &r, &g, &b) == 3)
	{
		int sum;
		sum = r*100 + g*10 + b;
		if(sum % 4 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
