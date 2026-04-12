/*
    coded by - PATHAKCODES ~~Revamped
    AIT PUNE , INDIA 
     
    "The Key is not will to win ......everybody has that "
    "It is will to prepare that is important"  
     
*/
     
#include <bits/stdc++.h>
 
using namespace std ;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pb push_back
const ll k = 1e9 +7;


int main ()
{
	IOS
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n ;
    cin >> n ;
    vector<ll> a(n,0);

    ll sum = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        sum += a[i];
        sum %= k ;
    }
    ll ans = 0 ;
    for(int i = 0 ;i < n ;i++){
        sum -= a[i];
        if (sum < 0) sum += k;
        ans += a[i]*sum ;
        ans%=k;
    }

    cout << ans << endl ;
}