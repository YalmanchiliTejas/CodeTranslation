#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back

ll const lim = 2e5+5;
ll const mod = 1000000007;
ll n, arr[lim+5], pref[lim+5];

ll solve() 
{ 
	ll sum = 0 ;
	for(int i=1;i<=n;i++) 
		pref[i] = (arr[i] + pref[i-1]) ;
	
	for(int i=1;i<=n;i++) {
		sum = (sum + ( (arr[i] % mod) * ((pref[n] - pref[i]) % mod) ) % mod) % mod ;
	}
	return sum ;
} 

int main() 
{ 
	cin >> n;
	for(ll i=1; i<=n; i++) cin >> arr[i];
	ll ans = (solve() + mod) % mod;
	cout<<ans<<endl;
    return 0; 
} 