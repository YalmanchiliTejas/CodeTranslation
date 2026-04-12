#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#define debug(x) cerr << __LINE__ << ' ' << #x << ':' << x << '\n'
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
template<class T> using pque = priority_queue<T, vector<T>, greater<T>>;
constexpr int inf = 1000000010;
constexpr ll INF = 1000000000000000010;
constexpr int mod1e9 = 1000000007;
constexpr int mod998 = 998244353;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
constexpr ll ten(int n) { return n ? 10 * ten(n - 1) : 1; };
int dx[] = { 1,0,-1,0,1,1,-1,-1 }; int dy[] = { 0,1,0,-1,1,-1,1,-1 };
void fail() { cout << "-1\n"; exit(0); } void no() { cout << "No\n"; exit(0); }
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }
template<class T> istream &operator >> (istream &s, vector<T> &v) { for (auto &e : v) s >> e; return s; }
template<class T> ostream &operator << (ostream &s, const vector<T> &v) { for (auto &e : v) s << e << ' '; return s; }

struct fastio {
	fastio() {
		cin.tie(0); cout.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(20);
		cerr << fixed << setprecision(20);
	}
}fastio_;

template<class T> class segtree {
	int n;
	vector<T> data;
	T id = 0;
	T operation(T a, T b) { return max(a, b); };
public:
	segtree(int _n) {
		n = 1;
		while (n < _n + 2) n <<= 1;
		data = vector<T>(2 * n, id);
	}
	segtree(vector<T> vec) {
		int _n = vec.size();
		n = 1;
		while (n < _n + 2) n <<= 1;
		data = vector<T>(2 * n, id);
		for (int i = 0; i < _n; i++) data[i + n] = vec[i];
		for (int i = n - 1; i >= 1; i--) data[i] = operation(data[i << 1], data[i << 1 | 1]);
	}
	void change(int i, T x) {
		i += n;
		data[i] = x;
		while (i > 1) {
			i >>= 1;
			data[i] = operation(data[i << 1], data[i << 1 | 1]);
		}
	}
	void add(int i, T x) { change(i, data[i + n] + x); }
	T get(int a, int b) {
		T left = id; T right = id;
		a += n; b += n;
		while (a < b) {
			if (a & 1) left = operation(left, data[a++]);
			if (b & 1) right = operation(data[--b], right);
			a >>= 1; b >>= 1;
		}
		return operation(left, right);
	}
	T get_all() { return data[1]; }
	T operator[](int i) { return data[i + n]; }
};

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	cin >> a;
	segtree<int> seg(a);
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int x, v;
			cin >> x >> v;
			x--;
			seg.change(x, v);
		}
		else if (type == 2) {
			int l, r;
			cin >> l >> r;
			l--;
			cout << seg.get(l, r) << '\n';
		}
		else if (type == 3) {
			int x, v;
			cin >> x >> v;
			x--;
			int ng = x, ok = n + 1;
			while (ok - ng > 1) {
				int mid = (ok + ng) / 2;
				if (seg.get(ng, mid) >= v) ok = mid;
				else ng = mid;
			}
			cout << ok << '\n';
		}
	}
}