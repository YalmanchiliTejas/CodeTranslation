#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using ll = long long;

const int mod = 1e9+7;



int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> v(n);
    rep(i,n) cin >> v[i];
    int64_t ans=0;
    int64_t tot=0;
    rep(i,n){
        tot+=v[i];
        tot%=mod;
    }
    rep(i,n-1){
        ll x=v[i];
        tot=(tot+mod-x)%mod;
        ll sum=(x*tot)%mod;
        ans+=sum;
        ans%=mod;
    }
    ans%=mod;
    cout << ans << endl;
}