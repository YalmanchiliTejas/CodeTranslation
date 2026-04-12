#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=10000005;
const int mod=998244353;
int n;
ll inv[max_n];
int main(){
    scanf("%d",&n);
    int k=n/2;
    ll ans=1;
    for(int i=1;i<=n;i++)ans=ans*3%mod;
    inv[1]=1;
    for(int i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    ll res=0;
    ll tmp=1,c=1;
    for(int i=0;i<k;i++){
        res+=tmp*c%mod;res%=mod;
        tmp=tmp*2%mod;
        c=c*(n-i)%mod*inv[i+1]%mod;
    }
    res=res*2%mod;
    ans=(ans-res+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}