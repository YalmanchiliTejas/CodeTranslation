#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int mod=998244353;
int f[N],n,s,x,ans=0;
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>x;
        for(int j=s-x;j>0;j--) f[j+x]=(f[j+x]+f[j])%mod;
        f[x]=(f[x]+i)%mod;
        ans=(ans+f[s])%mod;
    }
    cout<<ans;
    return 0;
}
