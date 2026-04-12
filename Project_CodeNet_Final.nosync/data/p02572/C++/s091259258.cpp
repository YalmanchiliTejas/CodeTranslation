#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

int main(){
    fast_io

    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    vector<ll> sum(n+1);
    sum[0] = 0;
    for(int i=1;i<=n;i++){
      sum[i] = a[i-1] + sum[i-1];
      // sum[i] %= mod;
    }

    ll ans = 0;
    for(int i=0;i<n;i++){
        ll res = (sum[n]-sum[i+1])%mod;
        ans += res * a[i];
        ans %= mod;
    }
    cout << ans%mod<<endl;
    return 0;
}
