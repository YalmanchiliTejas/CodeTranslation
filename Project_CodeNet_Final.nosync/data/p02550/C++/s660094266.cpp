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

constexpr ll mod = mod998;

int main() {
	ll n, x, m;
	cin >> n >> x >> m;
	vector<bool> used(m);
	vector<ll> a;
	ll ans = 0;
	while (n--) {
		if (used[x]) {
			n++;
			break;
		}
		used[x] = true;
		ans += x;
		a.pb(x);
		x *= x; x %= m;
	}
	if (n > 0) {
		vector<ll> p; bool flag = false;
		for (int i : a) {
			if (i == x) flag = true;
			if (flag) p.pb(i);
		}
		int sz = p.size();
		ll sum = accumulate(all(p), 0ll);
		ans += sum * (n / sz);
		n %= sz;
		rep(i, n) ans += p[i];
	}
	cout << ans << '\n';
}