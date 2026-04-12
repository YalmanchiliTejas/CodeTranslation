#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ll MAXN = 51;
ll a[MAXN];
ll p[MAXN];

ll dfs(ll n, ll x) {
	if (n == 0){
		return 1;
	}

	ll len = a[n-1];
	if (x == 1){
		return 0;
	} else if (x <= len + 1) {
		return dfs(n-1, x-1);
	} else if (x == len + 2) {
		return p[n-1] + 1;
	} else if (x <= 2*(len+1)) {
		return dfs(n-1, x-(len+2)) + p[n-1] + 1;
	} else {
		return 2*p[n-1] + 1;
	}
}

int main() {
	ll N, X;
	cin >> N >> X;

	//レベルLバーガーの厚さとパティの枚数を求める
	a[0] = 1;
	p[0] = 1;
	for (int ii = 1; ii <= N; ++ii){
		a[ii] = 2 * a[ii-1] + 3;
		p[ii] = 2 * p[ii-1] + 1;
	}

	ll ans = dfs(N, X);

	cout << ans << "\n";

	return 0;
}
