#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i=0; i < (ll)(n); i++)

ll MOD=1000000007;

int main(void){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    vector<ll> sum(n);
    sum[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        sum[i]=(a[i]+sum[i+1])%MOD;
    }
    ll ans=0;
    rep(i,n-1)ans=(ans+(a[i]*sum[i+1])%MOD)%MOD;
    cout<<ans<<endl;
}