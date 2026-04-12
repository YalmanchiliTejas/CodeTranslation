#include<stdio.h>

int main(void)
{
	bool *J;
	int f1, n, m, k, t, out;
	
	J = new bool [1000001];
	while(scanf("%d %d",&n, &m) && n+m > 0)
	{
		t = 0;
		out = 0;
		
		for(f1 = 1; f1 <= 1000001; f1++)
			J[f1] = false;
			
		for(f1 = 1; f1 <= n; f1++)
		{
			scanf("%d",&k);
			J[k] = true;
		}
		for(f1 = 1; f1 <= m; f1++)
		{
			scanf("%d",&k);
			J[k] = true;
		}
		for(f1 = 1; f1 <= 1000001; f1++)
		{
			if(J[f1])
			{
				if(out == 0 || f1 - t > out)
					out = f1 - t;
				t = f1;
			}
		}
		printf("%d\n",out);
	}
	return 0;
}