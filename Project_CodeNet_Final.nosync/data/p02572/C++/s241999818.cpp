#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int n;cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    int pre[n+1]={0};
    for(int i=1;i<=n;i++){
        pre[i]=(pre[i-1]+a[i])%mod;
        pre[i]%=mod;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=(a[i]*pre[i-1])%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
}
