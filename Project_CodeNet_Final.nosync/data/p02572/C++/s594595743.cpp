#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int mod=1e9+7;
int n,a[200010];
long long ans,sum;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) {
        ans+=sum*a[i]%mod;
        ans%=mod;
        sum+=a[i];
        sum%=mod;
    }
    printf("%lld\n",ans);
}