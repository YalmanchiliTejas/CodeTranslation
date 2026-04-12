#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll mod=1e9+7;
    ll n;
    cin >> n;
    ll wa=0;
    ll se=0;
    ll a;

    rep(i,n){
        cin >> a;
        wa+=a;
        se+=a*a;
        se=se%mod;
    }

    wa=wa%mod;

    ll ans;
    ans=wa*wa-se;
    ans=ans%mod;
    if(ans%2==1){
        ans+=mod;
    }
    cout << ans/2 << endl;

    

    return 0;
}