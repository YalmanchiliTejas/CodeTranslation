#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll mod = 1000000007;
    
    ll n;
    cin >> n;
    
    ll sum = 0;
    
    ll a[n];
    for (ll i=0 ; i<n ; i++) {
		cin >> a[i];
		sum += a[i];
	}
	
	sum -= a[0];
	
	ll ans = 0;
	
	for (ll i=0 ; i<n-1 ; i++) {
		ans = (ans%mod + (sum%mod * a[i]%mod)%mod)%mod;
		sum -= a[i+1];
	}
	
	cout << ans << "\n";
    
}
