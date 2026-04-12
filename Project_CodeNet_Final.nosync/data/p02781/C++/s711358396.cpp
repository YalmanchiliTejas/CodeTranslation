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
string num, mx;
int k, d;

int calc (int z, int itr) {
	if (z == 0) {
		return (num <= mx);
	}
	int res = 0;
	for (int i = '1'; i <= '9'; i++) {
		for (int j = itr + 1; j < d; j++) {
			num[j] = i;
			res += calc(z - 1, j);
			num[j] = '0';
		}
	}
	return res;
}

int f (int n, int m) {
	int res = 1;
	for (int i = 0; i < m; i++)
		res = (res * (n--));
	for (int i = 1; i <= m; i++)
		res /= i;
	for (int i = 0; i < m; i++)
		res *= 9;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	/* --- */
	cin >> mx >> k;
	d = sz(mx);
	num = mx;
	For(i, 1, sz(num)) num[i] = '0';
	int ans = calc(k - 1, 0);
	dbg(ans);
	for (int i = '1'; i < mx[0]; i++) ans += f(d - 1, k - 1);	
	ans += f(d - 1, k);
	cout << ans << '\n';
}

