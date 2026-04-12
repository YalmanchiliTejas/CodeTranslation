#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	ll n;
	cin >> n;
	ll a[n];
	rep(i, 0, n){
		cin >> a[i];
	}
	sort(a, a+n);
	
	ll ans = 0;
	ll l = a[n-1];
	ll r = a[n-1];
	bool isl;
	for(ll i = 0; i < n-1; i++){
		
		ll m = (i%2 == 0)? a[i/2] : a[n-2-i/2];
		
		if(i%2 == 0 || i == n-2){	
			if(abs(l-m) > abs(r-m)){
				ans += abs(l-m);
				l = m;
				isl = true;
			}
			else{
				ans += abs(r-m);
				r = m;
				isl = false;
			}
		}
		else{
			if(isl){
				ans += abs(l-m);
				l = m;
			}
			else{
				ans += abs(r-m);
				r = m;
			}
		}
	}
	
	print(ans)
	return 0;
}