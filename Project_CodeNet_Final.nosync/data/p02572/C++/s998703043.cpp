#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG

using namespace std;
typedef long long ll;
typedef vector<ll> vel;
typedef vector<string> ves;
typedef vector<int> vei;
typedef vector<vector<ll>> vvel;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REP(a, b, m) for (ll a = (ll)(b); a < (ll)(m); a++)

int main() {
    ll mod=1000000007;
    ll n;cin>>n;
    vel a(n);
    vel sum(n);
    rep(i,n){
        cin>>a[i];
        if(i==0){
            sum[i]=a[i];
        }else{
            sum[i]=(sum[i-1]+a[i]);
        }
    }
    ll ans=0;
    rep(i,n){
        if(i==n-1){
            break;
        }else {
            ans=(ans+a[i]*((sum[n-1]-sum[i])%mod))%mod;
        }
    }
    cout<<ans%mod<<endl;
}