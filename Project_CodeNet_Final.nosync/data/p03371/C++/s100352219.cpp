#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define For(i, a, b) for (int i = int(a); i < int(b); i++)
#define Dor(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define Foz(i, a) For(i, 0, a)
#define Doz(i, a) Dor(i, 0, a)
#define Trav(e, v) for (auto& e : v)
#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<ii>;
template <typename T> bool ckmin (T& a, T b) { return (b < a) ? a = b, 1 : 0; }
template <typename T> bool ckmax (T& a, T b) { return (b > a) ? a = b, 1 : 0; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef XVENOM
	#define errp(...) fprintf(stderr, __VA_ARGS__)
	#define dbg(...) errp("[%s]: ", #__VA_ARGS__), dbg_str(__VA_ARGS__)
#else
	#define errp(...)
	#define dbg(...)
#endif
template <typename U, typename V> string to_string (pair<U, V>);
string to_string (string& e) { return "\"" + e + "\""; }
string to_string (char e) { return "\'" + string(1, e) + "\'"; }
string to_string (bool e) { return e ? "true" : "false"; }
template <typename T> string to_string (T e) {
	string s = "[ ";
	for (auto& x : e) s += to_string(x) + " ";
	return s + "]";
}
template <typename U, typename V> string to_string (pair<U, V> e) {
	return "(" + to_string(e.first) + ", " + to_string(e.second) + ")";
}
void dbg_str () { errp(" \n"); }
template <typename U, typename... V> void dbg_str (U u, V... v) {
 	errp(" %s", to_string(u).c_str()); dbg_str(v...);
}
/* --- */
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	/* --- */
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = a * x + b * y;
	Foz(i, max(x, y) + 1) {
		int t = 2 * c * i +
		max(0, x - i) * a +
		max(0, y - i) * b;
		ckmin(ans, t);
	}
	cout << ans << '\n';
}

