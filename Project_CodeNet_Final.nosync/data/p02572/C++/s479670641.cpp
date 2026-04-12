#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, b, n) for (int i = (b); i < (n); i++)
using namespace std;
using ll = long long;
const ll M = 1000000007;

int main() {
	ll n, ans = 0;
	cin >> n;
	vector<ll> a(n + 10);
	vector<ll> s(n + 10);
	rep(i, n) {
		cin >> a[i];
		s[i + 1] += s[i] + a[i];
		s[i + 1] %= M;
	}
	rep(i, n - 1) {
		if (s[n] - s[i + 1] < 0) ans += a[i] * (s[n] - s[i + 1] + M);
		else ans += a[i] * (s[n] - s[i + 1]);
		ans %= M;
	}
	cout << ans << endl;
}