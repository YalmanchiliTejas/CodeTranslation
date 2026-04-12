#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&-x)
using namespace std;
const int N = 1e4+7, M = 1e2+7, p = 1e9+7;
char s[N];
int f[N][M][2];
int main()
{
	int n, d, sum = 0, ans;
	scanf("%s%d", s+1, &d);
	f[0][0][0] = 1;
	n = strlen(s+1);
	for(int i = 1; s[i] != '\0'; i++)
	{
		for(int j = 0; j < d; j++)
		{
			for(int k = 0; k <= 9; k++)
			{
				f[i][(j+k)%d][1] = (f[i][(j+k)%d][1]+f[i-1][j][1])%p;
			}
		}
		for(int j = 0; j < s[i]-'0'; j++)
		{
			f[i][(sum+j)%d][1] = (f[i][(sum+j)%d][1]+f[i-1][sum][0])%p;
		}
		f[i][(sum+s[i]-'0')%d][0] = (f[i][(sum+s[i]-'0')][0]+f[i-1][sum][0])%p;
		sum = (sum+s[i]-'0')%d;
	}
	ans = (f[n][0][0]+f[n][0][1]-1)%p;
	printf("%d\n", (ans+p)%p);
	return 0;
}