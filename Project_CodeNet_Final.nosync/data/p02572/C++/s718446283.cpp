#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int n;
ll a[maxn], s[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i) 
		cin >> a[i], s[i] = (s[i - 1] + a[i]) % mod;
	ll ans = 0;
	for(int i = 1; i < n; ++i)
		ans = (ans + a[i] * (s[n] - s[i] + mod) % mod) % mod;
	cout << ans << endl;
	return 0;
}