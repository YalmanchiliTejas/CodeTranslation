#pragma warning(disable:4996)
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (ll i = (ll)(a); i<(ll)(b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) begin(a), end(a)
#define TPL template
#define TNM typename

using ll = long long;
using ull = unsigned long long;
using vb = vector<bool>;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vvb = vector<vb>;
using vvi = vector<vi>;
using vvll = vector<vll>;
TPL<TNM K, TNM V> using umap = unordered_map<K, V>;
TPL<TNM K, TNM V> using uset = unordered_set<K, V>;

TPL <class T = int> inline T IN() { T x; cin >> x; return x; }
TPL<class T> inline void OUT(const T &x) { cout << x << "\n"; }
void YESNO(bool c) { OUT(c ? "YES" : "NO"); };
void YesNo(bool c) { OUT(c ? "Yes" : "No"); };
void bOUT(bool c, string s, string t) { OUT(c ? s : t); }
struct pre_ { pre_() { cin.tie(nullptr); ios::sync_with_stdio(false); /*cout << fixed << setprecision(6);*/ } } pre__;

TPL<TNM V, TNM H> void resize(vector<V>& v, const H h) { v.resize(h); }
TPL<TNM V, TNM H, TNM ... T> void resize(vector<V>& v, const H& h, const T ... t) { v.resize(h); for (auto& _v : v) resize(_v, t ...); }
TPL<TNM V, TNM T> void fill(V& x, const T& val) { x = val; }
TPL<TNM V, TNM T> void fill(vector<V>& vec, const T& val) { for (auto& v : vec) fill(v, val); }
TPL<TNM T> vector<T> make_v(size_t a) { return vector<T>(a); }
TPL<TNM T, TNM... Ts> auto make_v(size_t a, size_t b, Ts... ts) { return vector<decltype(make_v<T>(b, ts...))>(a, make_v<T>(b, ts...)); }

TPL<TNM T> using vec2 = decltype(make_v<T>(0, 0));
TPL<TNM T> using vec3 = decltype(make_v<T>(0, 0, 0));
TPL<TNM T> using vec4 = decltype(make_v<T>(0, 0, 0, 0));
TPL<TNM T> using vec5 = decltype(make_v<T>(0, 0, 0, 0, 0));

int main(void) {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int mn = min(X, Y);
	int mx = max(X, Y);
	int cost1 = (A + B) * mn;
	/*

	*/

	int cost2 = mn * 2 * C;

	int ans = min(cost1, cost2);
	if (X > Y) {
		ans += (mx - mn) * A;
	}
	else {
		ans += (mx - mn) * B;
	}

	int cost3 = mx * 2 * C;

	ans = min(cost3, ans);
	OUT(ans);

	return 0;
}