#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int long long
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define sz(x) (int)x.size()
const int mod = 1e9 + 7;
// const int mod1 = 998244353;
typedef long double f80;
 
#ifndef LOCAL
#pragma GCC optimize ("O2")
#define endl '\n'
#endif
 
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
 
ll pwr(ll a,ll b, ll mod){
    a %= mod;
    int ans = 1;
    while(b){
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
 
string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void debug1(int a[], int l,int r) {
	#ifdef LOCAL
		vector<int> temp(a + l, a + r + 1);
		debug(temp);
	#endif
}

typedef unsigned long long ui64;
inline ui64 mul_mod(ui64 a,ui64 b,ui64 mod, f80 i=0){
if(!i) i = f80(1) / f80(mod);
ui64 y = ui64(f80(a) * f80(b) * i + f80(1) / 2);
ui64 r = a * b - y * mod;
if(ll(r) < 0) r += mod;
return r;
}

const int N = 2e5 + 5;

pii lol[2 * N];

map<int,int> m;

void solve(){
	int xmin = 1e18, xmax = -1, ymin = 1e18, ymax = -1;
	int n;
	cin >> n;
	int c = 0;
	fr(i, 1, n) {
		int x, y;
		cin >> x >> y;
		lol[++c] = {x, i};
		lol[++c] = {y, i};
		if(x > y) swap(x, y);
		xmin = min(xmin, x);
		xmax = max(xmax, x);
		ymin = min(ymin, y);
		ymax = max(ymax, y);
	}
	int ans = (xmax - xmin) * (ymax - ymin);
	sort(lol + 1, lol + c + 1);
	if(lol[1].se != lol[c].se) {
		int pt = 0, dist = 0;
		fr(i, 1, c - 1) {
			while(pt + 1 < c && dist != n) {
				pt++;
				m[lol[pt].se]++;
				if(m[lol[pt].se] == 1) dist++;
			}
			if(dist == n) {
				ans = min(ans, (lol[c].fi - lol[1].fi) * (lol[pt].fi - lol[i].fi));
			}
			m[lol[i].se]--;
			if(!m[lol[i].se]) {
				dist--;
			}
		}
	}
	cout << ans;
}

signed main(){
    IO;
    #ifdef LOCAL
        freopen("inp.txt","r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    fr(tt, 1, t){
        solve();
    }
    return 0;
} 