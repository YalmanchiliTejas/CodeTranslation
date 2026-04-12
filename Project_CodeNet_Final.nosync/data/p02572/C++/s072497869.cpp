#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll inf = 1e18;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll arr[n];
    ll s = 0;
    ll pref = 0;
    for(ll &i : arr)
        cin >> i , s += i;
    int mod = 1e9 + 7;
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        pref += arr[i];
        ans = ans + ((arr[i] % mod) * ((s - pref) % mod)) % mod;
        ans = ans % mod;
    }
    cout<<ans;
}
