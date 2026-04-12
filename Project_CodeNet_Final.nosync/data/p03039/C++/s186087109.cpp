#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}

ll bin_pow(ll x, ll n, ll mod=MD){
	ll res = 1LL;
	for(; n > 0; n >>=1, x = x*x %mod) if(n & 1) res = res * x %mod;
	return res;
}
ll nCk_mod(ll n, ll k, int mod=MD) {
	if(k > n || n <0 || k <0) return 0;
	ll ret = 1, rt2 = 1;
	for(ll i=n-k+1; i<n+1; i++) ret = ( ret * i) % mod;
	for(ll i=1; i<k+1; i++) rt2 = ( rt2 * i) % mod;
	return ( ret * bin_pow( rt2, mod-2, mod)) % mod;
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >>n >>m >>k;
	
	ll cnd = 0;
	rep(i, n) (cnd += (ll)i*(i+1)/2 * m %MD * m) %=MD;
	rep(i, m) (cnd += (ll)i*(i+1)/2 * n %MD * n) %=MD;
	ll ans = nCk_mod(n*m-2, k-2) * cnd % MD;
	cout << ans <<"\n";
	return 0;
}
