#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define emp emplace

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int N = 3010;
int n;
int a[N];

ll pd[N][N][2];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a+i);
	for (int s = 1; s <= n; s++)
	{
		for (int i = 1; i + s - 1 <= n; i++)
		{
			int j = i + s - 1;
			pd[i][j][0] = max(pd[i][j-1][1] + a[j], pd[i+1][j][1] + a[i]);
			pd[i][j][1] = min(pd[i][j-1][0] - a[j], pd[i+1][j][0] - a[i]);
		}
	}
	printf("%lld\n", pd[1][n][0]);
	return 0;
}

