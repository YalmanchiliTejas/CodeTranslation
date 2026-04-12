#include <bits/stdc++.h>
using namespace std;
int d[10005][3][105],n,m;
char s[10005];

int main()
{
    scanf("%s %d", &s, &n);
    m = strlen(s);
	d[0][0][0] = 1;
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < 2;j++)
		{
			int x = j ? 9 : s[i]-48;
			for(int l = 0;l <= x;l++)
			{
				for(int k = 0;k < n;k++)
					(d[i+1][j | l < x][(k+l) % n] += d[i][j][k]) %= 1000000007;
			}
		}
	}
	cout << (d[m][0][0]+d[m][1][0]-1+1000000007) % 1000000007;
}