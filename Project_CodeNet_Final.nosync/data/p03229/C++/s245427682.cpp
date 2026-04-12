#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll powk(ll a, ll n){
    ll r = 1;
    for(ll i = 0;i < n;i++){
        r *= a;
    }

    return r;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    ll ans = 0;
    if(n % 2 == 0){
        for(ll i = 0;i < n;i++){
            if(i < n / 2 - 1){
                ans += a[i] * -2;
            }
            else if(i > n / 2){
                ans += a[i] * 2;
            }
            else if(i == n / 2 - 1){
                ans += a[i] * -1;
            }
            else{
                ans += a[i];
            }
        }
    }
    else{
        for(ll i = 0;i < n;i++){
            if(i < n / 2 - 1){
                ans += a[i] * -2;
            }
            else if(i > n / 2){
                ans += a[i] * 2;
            }
            else{
                ans += a[i] * -1;
            }
        }
        ll t = 0;
        for(ll i = 0;i < n;i++){
            if(i < n / 2){
                t += a[i] * -2;
            }
            else if(i > n / 2 + 1){
                t += a[i] * 2;
            }
            else{
                t += a[i];
            }
        }
        ans = max(ans, t);
    }

    cout << ans;

    return 0;
}