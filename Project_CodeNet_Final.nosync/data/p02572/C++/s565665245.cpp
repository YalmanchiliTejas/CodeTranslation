#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
const int maxn=2e5+10;
LL a[maxn],sum[maxn];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        sum[i]=sum[i+1]+a[i];
        sum[i]%=mod;
    }
    LL res=0;
    for(int i=1;i<=n;i++){
        LL pre=a[i]*sum[i+1]%mod;
        res+=pre;
        res%=mod;
    }
    printf("%lld\n",res);
    return 0;
}
