#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn=2e5+100;
const ll mod=1e9+7;
ll t,a[maxn],sum[maxn];
int main(){
    //ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    //freopen("in.txt","r",stdin);
    cin>>t;
    sum[0]=0;
    for(int i=1;i<=t;i++){
        cin>>a[i];
        sum[i]=(sum[i-1]+a[i]);
    }
    ll ans=0;
    for(int i=1;i<t;i++){
        ans+=a[i]*((sum[t]-sum[i])%mod)%mod;
        ans%=mod;
    }
    cout<<(ans+mod*100)%mod<<endl;
    return 0;
}