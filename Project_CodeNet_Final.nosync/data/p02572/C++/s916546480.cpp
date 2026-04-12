#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define PI 3.14159265358979323846
#define fi first
#define se second
 
ll mod = 1e9+7;
 
ll max(ll a, ll b ) {
	if(a>b)
		return a;
	else return b;
}
ll min(ll a, ll b ) {
	if(a<b)
		return a;
	else return b;
}

int main() {
	ll ttt;
	//cin>>ttt;
	ttt = 1;
	while(ttt--) {
		ll n; cin>>n;
		ll sum = 0;
		ll a[n+1]; for(int i=1; i<=n; i++) { cin>>a[i]; sum += a[i]; }
		ll pre[n+1]; pre[0] = 0;
		sum = sum%mod;
		pre[1] = (sum - a[1]+mod)%mod;
		for(int i=2; i<=n; i++) {
			pre[i] = (pre[i-1] - a[i]+mod)%mod;
		}
		ll ans = 0;
		for(int i=1; i<=n-1; i++) {
			ans = (ans + (a[i]*pre[i]) % mod) %mod;
		}
		cout<<ans;
	}
	return 0;
}
