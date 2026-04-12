#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector
#define pb push_back

vec<vec<int>> p;
int n, m;

int ans = 0;
vec<int> check;

void solve(vec<int> dp, int point)
{
	rep(i, p[point].size()) {
		int x = p[point][i];
		if (!dp[x]) {
			dp[x] = 1;
			solve(dp, x);
			dp[x] = 0;
		}
	}
	if (dp == check) ans++;
}

int main(void)
{
	cin >> n >> m;
	p.resize(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		p[a].pb(b);
		p[b].pb(a);
	}

	check.resize(n);
	rep(i, n) check[i] = 1;
	vec<int> give(n);
	give[0] = 1;
	solve(give, 0);
	cout << ans << endl;
	return 0;
}
