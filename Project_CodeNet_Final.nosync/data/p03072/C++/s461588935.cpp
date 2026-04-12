#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAXX 100005

#define PI 3.14159265358979323846264338327950

#define ll signed long long int

ll a[MAXX];
multiset<ll> ms;
multiset<ll>::iterator it;
signed main()
{
    FAST;
    ll n, mx = 0;
    cin >> n;
    ll ans = 1;
    for(ll i = 0;i < n; i++){
    	cin >> a[i];
    	if(a[i] >= mx){
    		mx = a[i]; ans ++;
		}
	}
	cout << ans-1;
}