#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 55, M = 1010;

int n;
LL f[N], p[N], x;

void solve()
{
	scanf("%d%lld", &n, &x);
	f[0] = p[0] = 1LL;
	for (int i = 1; i <= n; i ++ ) 
	{
		f[i] = 2 * f[i - 1] + 3LL;
		p[i] = 2 * p[i - 1] + 1LL;
	}	
	
	LL res = 0;
	for (int i = n; i >= 0; i -- )
	{
		if (x == 0) break;
		if (x == f[i])
		{
			res += p[i];
			break;
		}

		if (x <= 1LL + f[i - 1]) x -- ;
		else
		{
			res += 1LL;
			if (i) res += p[i - 1];
			x -= f[i - 1] + 2LL;
		}
	}
	printf("%lld\n", res);
}

int main()
{
	int T = 1;
	// scanf("%d", &T);
	// cin >> T;
	while (T -- ) solve();
	return 0;
}