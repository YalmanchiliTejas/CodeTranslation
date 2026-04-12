#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll,ll> cnt;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        ll x = a[i];
        for(ll j=2;j*j<=x;j++){
            if(x%j==0){
                cnt[j] += a[i];
                while(x%j==0) x /= j;
            }
        }
        if(x != 1) cnt[x] += a[i];
    }
    ll ans = 0;
    for(auto p : cnt){
        ans = max(ans, p.second);
    }
    cout << ans << endl;
    return 0;
}
