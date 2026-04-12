#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define Rep(i, a, b) for(ll i = a; i <= b; i++)
#define repr(i, a, b) for(ll i = b-1; i >= a; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
// const ll INF = 1LL << 60;
const ll INF = 100000000000;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << H << " ";
  debug_out(T...);
}
#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif          // -D_DEBUG をつけて実行 cf)可変引数
 
// rep(i, 0, sz(v)) cout << v[i] << " \n"[i==sz(v)-1];
 
////////////////////////////////////////////////////////


int main() {
	ll n; cin >> n;
	Vl a(n);
	rep(i, 0, n) cin >> a[i];
	Vl wa(n, 0);
	wa[n-1] = a[n-1];
	repr(i, 0, n-1) wa[i] = (a[i] + wa[i+1])%MOD;
	ll ans = 0;
	// rep(i, 0, sz(wa)) cout << wa[i] << " \n"[i==sz(wa)-1];
	rep(i, 0, n-1){
		ans =  (ans +((a[i]*wa[i+1])%MOD))%MOD;
	}
	co(ans);

    return 0;
}