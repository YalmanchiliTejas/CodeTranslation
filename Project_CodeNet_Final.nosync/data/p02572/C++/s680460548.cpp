#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
const ll mod=1e9+7;
ll a[N],sum[N]={0};
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=(a[i]+sum[i-1]);
    }
    ll ans=0;
    for(int i=1;i<=n-1;i++){
        ans=(ans+a[i]*((sum[n]-sum[i])%mod)%mod)%mod;
    }
    cout<<ans;
}


