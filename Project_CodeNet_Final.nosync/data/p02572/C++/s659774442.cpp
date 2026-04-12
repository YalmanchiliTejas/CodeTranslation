#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main(){
    int n;cin>>n;
    ll mod=1e9+7;
    vector<int> a(n);
    vector<int> b(n+1);
    rep(i,n){
        cin>>a[i];
        b[i+1]=(b[i]+a[i])%mod;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ll tmp=b[n]-b[i+1];
        if(tmp<0)tmp+=mod;
        ans+=(a[i]*tmp)%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
}