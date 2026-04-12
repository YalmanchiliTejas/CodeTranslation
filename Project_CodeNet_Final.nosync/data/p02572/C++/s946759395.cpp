#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
	ll N, mod = 1000000007;
	cin >> N;
	vector<ll> X(N);
	rep(i, N) { cin >> X.at(i); }
	ll A = 0, B = 0;
	rep(i, N) {
		A += X.at(i);
		A %= mod;
		B += X.at(i) * X.at(i);
		B %= mod;
	}
	ll pre = (A * A - B) % mod;
	if (pre % 2 == 0) {
		cout << pre / 2;
	} else {
		cout << (pre + mod) / 2;
	}
}