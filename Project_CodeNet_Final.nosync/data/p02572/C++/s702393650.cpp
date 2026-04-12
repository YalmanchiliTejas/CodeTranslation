#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;

#define sz(v) (int)v.size()

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
}


const int MAX = 2e5 + 100;
ll a[MAX], pre[MAX];

const int MOD = 1000000007;

int main() {
	PLAY();
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = a[i];
	}

	for (int i = 1; i <= n; i++)
		pre[i] += pre[i - 1];

	ll res = 0;
	for (int i = 1; i <= n; i++) {
		ll sum = pre[n] - pre[i];
		ll x = ((sum % MOD) * (a[i] % MOD)) % MOD;
		res = (res% MOD + x % MOD) % MOD;
	}

	cout << res % MOD << endl;

	return 0;
}