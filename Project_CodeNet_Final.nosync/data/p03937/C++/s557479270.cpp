#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
char s[maxn][maxn];
int l[maxn];
int n, m;
void no() { puts("Impossible"); exit(0);}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(s[i][j] == '#')
			{
				l[i] = j; 
				break;
			}
	l[n + 1] = n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			if(l[i] <= j && j <= l[i + 1] && s[i][j] == '.')
				no();
			if(j > l[i + 1] && s[i][j] == '#')
				no();
		}
	puts("Possible");
	return 0;
}
	