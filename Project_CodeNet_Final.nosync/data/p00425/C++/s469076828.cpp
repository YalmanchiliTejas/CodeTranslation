#include <stdio.h>
#include <string.h>

int main()
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n == 0)
		{
			break;
		}
		int d = 1;
		int m[6] = {1,2,3,5,4,6};
		for(int i = 0; i < n; i++)
		{
			char w[100];
			scanf("%s",w);
			if(strcmp(w,"North") == 0)
			{
				int ww = m[0];
				m[0] = m[1];
				m[1] = m[5];
				m[5] = m[3];
				m[3] = ww;
			}
			if(strcmp(w,"East") == 0)
			{
				int ww = m[0];
				m[0] = m[4];
				m[4] = m[5];
				m[5] = m[2];
				m[2] = ww;
			}
			if(strcmp(w,"West") == 0)
			{
				int ww = m[0];
				m[0] = m[2];
				m[2] = m[5];
				m[5] = m[4];
				m[4] = ww;
			}
			if(strcmp(w,"South") == 0)
			{
				int ww = m[0];
				m[0] = m[3];
				m[3] = m[5];
				m[5] = m[1];
				m[1] = ww;
			}
			if(strcmp(w,"Right") == 0)
			{
				int ww = m[1];
				m[1] = m[2];
				m[2] = m[3];
				m[3] = m[4];
				m[4] = ww;
			}
			if(strcmp(w,"Left") == 0)
			{
				int ww = m[1];
				m[1] = m[4];
				m[4] = m[3];
				m[3] = m[2];
				m[2] = ww;
			}
			d += m[0];
		}
		printf("%d\n",d);
	}
	return 0;
}