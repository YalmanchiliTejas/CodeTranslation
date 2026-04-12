//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 998244353;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll fact[10001001], inv[10001001], p3[10001001];
ll bp(ll a, ll p) {
	ll res = 1;
	while(p) {
		if(p&1) res = (res*a)%mod;
		a=(a*a)%mod;
		p>>=1;
	}
	return res;
}
ll nck(ll n, ll k) {
	ll res = (fact[n]*inv[k])%mod;
	return (res*inv[n-k])%mod;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	fact[0]= p3[0] = 1;
	for(int i = 1; i <= 10000000; i++)
		fact[i] = (fact[i-1]*i)%mod;
	inv[10000000]=bp(fact[10000000], mod-2);
	for(int i = 10000000; i--;)
		inv[i] = (inv[i+1]*(i+1))%mod;
	for(int i = 1; i <= 10000000; i++)
		p3[i] = (p3[i-1]*2)%mod;
	ll ans = bp(3, n);
	for(ll x = (n/2)+1; x <= n; x++) {
		ans = (mod+ans - (2ll*p3[n-x]*nck(n, x))%mod)%mod;
	}
	cout << ans;
}
