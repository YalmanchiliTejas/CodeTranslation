#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ll MAXN = 51;
ll memo[MAXN];

ll powfunc(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

ll dfs(ll n, ll x) {
	if (n == 0){
		return memo[0] = 1;
	}
	if (memo[n] != 0) {
		return memo[n];
	}

	//A[n-1]の長さを求める
	ll alen = powfunc(2, n+1) - 3;
	if (x > 2 * (alen + 2)){
		return memo[n] = 2 * dfs(n-1, alen) + 1;
	} else if (x > alen + 2) {
		return dfs(n-1, x - (alen + 2)) + 1 + dfs(n-1, alen);
	} else if (x > alen + 1) {
		return 1 + dfs(n-1, alen);
	} else if (x > 1) {
		return dfs(n-1, x-1);
	} else {
		return 0;
	}
}

int main() {
	ll N, X;
	cin >> N >> X;

	ll ans = dfs(N, X);

	cout << ans << "\n";

	return 0;
}
