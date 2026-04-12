#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

const long long mod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<long long> a(n); cin >> a;
	long long ans = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		if (i) {
			ans = (ans + ((sum * a[i]) % mod)) % mod;
		}
		sum = (sum + a[i]) % mod;
	}
	cout << ans << '\n';
}
