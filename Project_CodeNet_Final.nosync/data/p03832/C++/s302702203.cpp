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

const int N = 1005;
int dp[N][N];
int ncr[N][N];
int par[N][N]; // par[i][j] -> partiton i into groups of j
int fact[N], ifact[N];

void solve(){
	fact[0] = 1;
	fr(i, 1, N - 1) {
		fact[i] = (fact[i - 1] * i) % mod;
	}
	ifact[N - 1] = pwr(fact[N - 1], mod - 2, mod);
	for(int i = N - 2; i >= 0; i--) {
		ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
	}
	assert(ifact[0] == 1);
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	fr(i, 0, n) {
		ncr[i][0] = 1;
		fr(j, 1, i) {
			ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % mod;
		}
	}
	fr(j, 1, n) {
		par[0][j] = 1;
		for(int i = j; i <= n; i += j) {
			par[i][j] = par[i - j][j] * ncr[i][j];
			par[i][j] %= mod;
		}
	}
	dp[a - 1][0] = 1;
	fr(i, a - 1, b - 1) {
		fr(j, 0, n) {
			fr(k, c, d) {
				if(j + k * (i + 1) > n) break;
				int n_ways = ncr[n - j][k * (i + 1)];
				n_ways = (n_ways * par[k * (i + 1)][i + 1]) % mod;
				n_ways = (n_ways * ifact[k]) % mod;
				dp[i + 1][j + k * (i + 1)] += dp[i][j] * n_ways;
				dp[i + 1][j + k * (i + 1)] %= mod;
			}
			dp[i + 1][j] += dp[i][j];
			if(dp[i + 1][j] >= mod) 
				dp[i + 1][j] -= mod;
		}
	}
	cout << dp[b][n];
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