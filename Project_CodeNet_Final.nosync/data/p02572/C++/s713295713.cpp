#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;
const double PI=acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	ll n; cin >> n;
	vector<ll> a(n);
	rep(i,0,n) cin >> a[i];
	vector<ll> b(n,0);
	rep(i,1,n){
		b[i] = (b[i-1] + a[i-1]) % MOD;
	}
	ll ans = 0;
	for(ll i = n-1; i >= 0; i--){
		ans += ((a[i] % MOD) * (b[i] % MOD)) % MOD;
	}
	ans %= MOD;
	cout << ans << endl;
}
