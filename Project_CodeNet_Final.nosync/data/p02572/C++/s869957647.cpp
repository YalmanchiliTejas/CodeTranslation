#include <bits/stdc++.h>
#define ll long long
#define N 3000003
#define endl "\n"
#define fcin ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
ll n , a[N] , sum , ans , mod = 1e9 + 7;

int main(){
fcin;
    cin >> n;
    for(ll i = 0 ; i < n ; i++) cin >> a[i] , sum += a[i];
    for(ll i = 0 ; i < n ; i++){
        sum -= a[i];
        a[i] %= mod;
        ans += (sum + mod )%mod * a[i];
        ans%=mod;
    }
    cout << ans << "\n";
}
