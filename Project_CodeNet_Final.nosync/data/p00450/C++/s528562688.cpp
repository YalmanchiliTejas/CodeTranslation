#include "stdio.h"

typedef struct
{
	int ban;
	int iro;
}nara;

nara q[100000];

int ans[1000];

int main()
{
	int nww = 0;
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n == 0)
		{
			break;
		}
		int ni = 2;
		int nb = 0;
		int w;
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&w);
			if(w != ni)
			{
				if((i + 1) % 2 == 1)
				{
					q[nb].ban = i;
					q[nb].iro = w;
					nb++;
				}
				else
				{
					if(nb == 1)
					{
						q[0].iro = w;
					}
					else
					{
						nb--;
					}
				}
				ni = w;
			}
		}
		int all = 0;
		for(int i = 0; i < nb; i++)
		{
			if(q[i].iro == 0)
			{
				if(i == nb - 1)
				{
					all = all + n - q[i].ban;
				}
				else
				{
					all = all + q[i + 1].ban - q[i].ban;
				}
			}
		}
		ans[nww] = all;
		nww++;
	}
	for(int i = 0; i < nww; i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}