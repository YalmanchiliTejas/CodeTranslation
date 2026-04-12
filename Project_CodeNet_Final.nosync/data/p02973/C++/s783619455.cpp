#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
#include <tuple>
#include <functional>
#include <bitset>
#define INF 1000000009
#define LINF 1000000000000000009
#define double long double
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T> bool chmax(T &a, const T&b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T&b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

template<class T>
class segtree {
	int n;
	vector<T> data;
	T def;
	function<T(T, T)> operation;
	function<T(T, T)> update;
	T _query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return def;
		if (a <= l && r <= b) return data[k];
		T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);
		T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);
		return operation(c1, c2);
	}
public:
	segtree(size_t _n, T _def, function<T(T, T)> _operation, function<T(T, T)> _update)
		:def(_def), operation(_operation), update(_update) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		data = vector<T>(2 * n - 1, def);
	}
	void change(int i, T x) {
		i += n - 1;
		data[i] = update(data[i], x);
		while (i > 0) {
			i = (i - 1) / 2;
			data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
		}
	}
	T query(int a, int b) {
		return _query(a, b, 0, 0, n);
	}
	T operator[](int i) {
		return data[i + n - 1];
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
		mp[a[i]]++;
	}
	sort(all(b));
	for (int i = 0; i < n - 1; i++) {
		if (b[i + 1] != b[i]) {
			mp[b[i + 1]] += mp[b[i]];
		}
	}
	for (int i = 0; i < n; i++) a[i] = mp[a[i]];
	segtree<int> seg(n + 2, 0, [](int a, int b) {return max(a, b); }, [](int a, int b) {return b; });
	for (int i = 0; i < n; i++) {
		int c = seg.query(a[i], n + 2);
		seg.change(a[i], c + 1);
	}
	cout << seg.query(0, n + 2) << endl;
}