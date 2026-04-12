#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
char s[55][55];
bool vis[55][55], md[55];
char ans[55];
int dp[55][55];
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		int cnt = 0;
		int minlen = 100, minpos = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", s[i] + 1);
			s[i][0] = strlen(s[i] + 1);
			if(s[i][0] < minlen)
			{
				minlen = s[i][0];
				minpos = i;
			}
			sort(s[i] + 1, s[i] + s[i][0] + 1);
		}
		bool flag, f;
		for(int i = 1; i <= s[minpos][0]; i++)
		{
			char x = s[minpos][i];
			flag = 1;
			for(int j = 1; j <= n; j++)
			{
				f = 0;
				for(int k = 1; k <= s[j][0]; k++)
				{
					if(s[j][k] == x && !vis[j][k])
					{
						f = 1;
						vis[j][k] = 1;
						break;
					}
				}
				if(f == 0)
				{
					for(int k = 1; k <= j; k++)
					{
						for(int l = 1; l <= s[k][0]; l++)
						{
							if(s[k][l] == x)
							{
								vis[k][l] = 0;
								break;
							}
						}
					}
					flag = 0;
					break;
				}
			}
			if(flag == 1)
				ans[++cnt] = x;
		}
		if(cnt == 0)
			printf("\n");
		else
		{
			for(int i = 1; i <= cnt; i++)
				printf("%c", ans[i]);
			printf("\n");
		}
	}
}