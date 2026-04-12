#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
	cin >> a[i];
    }
    ll s = 0;
    for (int i = 0; i < n; i++) {
	s += a[i];
	s %= MOD;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
	s -= a[i];
	s %= MOD;
	if ( s < 0) s += MOD;
	ans += (a[i] * s) % MOD;
	ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}

