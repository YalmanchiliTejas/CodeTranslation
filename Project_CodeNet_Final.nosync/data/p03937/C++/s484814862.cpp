#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define MOD ((int)(1e9) + 7)

const int N = ((int)8) + 1;

int n,m;
char g[N][N];
int cnt;


int main ()
{
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char c;
			scanf(" %c",&c);
			if (c == '#')
				cnt++;
		}
	}
	if (cnt == n + m - 1)
		return printf("Possible"),0;
	printf("Impossible");
}