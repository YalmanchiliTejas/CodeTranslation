//waz
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)((x).size()))

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long uint64;

#define gi(x) ((x) = F())
#define gii(x, y) (gi(x), gi(y))
#define giii(x, y, z) (gii(x, y), gi(z))

int F()
{
	char ch;
	int x, a;
	while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') ch = getchar(), a = -1;
	else a = 1;
	x = ch - '0';
	while (ch = getchar(), ch >= '0' && ch <= '9')
		x = (x << 1) + (x << 3) + ch - '0';
	return a * x;
}

int n, m;

char str[20][20];

int main()
{
	gii(n, m);
	for (int i = 1; i <= n; ++i) scanf("%s", str[i] + 1);
	int x = 1, y = 1;
	if (str[x][y] == '.')
	{
		puts("Impossible");
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cnt += (str[i][j] == '#');
	for (int i = 1; i < cnt; ++i)
	{
		if (str[x + 1][y] == '#') ++x;
		else if (str[x][y + 1] == '#') ++y;
		else 
		{
			puts("Impossible");
			return 0;
		}
	}
	puts("Possible");
	return 0;
}

