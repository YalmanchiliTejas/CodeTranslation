#include <bits/stdc++.h>
#define range(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, b) for (int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x) cerr << #x << " = " << (x) << endl;
#define int long long
using namespace std;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}

template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
	rep(i, v.size()) { os << v[i] << (i == v.size() - 1 ? "" : " "); }
	return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
	for (T& x : v) { is >> x; }
	return is;
}

set<int> prime;

map<int, int> primeFactor(int n) {
	map<int, int> res;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			prime.emplace(i);
			++res[i];
			n /= i;
		}
	}
	if (n != 1) {
		res[n] = 1;
		prime.emplace(n);
	}
	return res;
}

signed main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	vector<map<int, int>> m(n);
	rep(i, n) { m[i] = primeFactor(a[i]); }

	int ans = 0;
	for (auto i : prime) {
		int cnt = 0;
		rep(j, n) {
			if (m[j].count(i)) { cnt += a[j]; }
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}

