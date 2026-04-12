#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef long double ld;
const ld pi = 4*atan((ld)1);
const ll mod = 1e9 + 7;
const ll inf = 922337203685477;
const ll nax = 2e5 + 5;

ll n;
ll a[nax], pref[nax];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		pref[i] = pref[i-1] + a[i];
		pref[i] %= mod;
	}
	ll ans = 0;
	for(ll i = n; i >= 2; i--){
		ans += a[i] * pref[i-1] % mod;
		ans %= mod;
	}
	cout << ans << '\n';
	
	
}

