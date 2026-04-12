#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i,p,q) for(ll i = p;i < q;i++)

int main(void){
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    rep(i,k+1,n+1){
        ll p,r;
        p = n / i;
        r = n % i;
        ans += p * max((ll)0, i - k);
        ans += max((ll)0, r - k + 1);
    }
    if(k == 0) ans -= n;
    cout << ans << endl;
}