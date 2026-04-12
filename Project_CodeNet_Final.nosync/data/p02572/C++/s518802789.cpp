#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define maxn 1000000
using namespace std;
long long s=0;
long long ans=0;
long long a[maxn];
int n;
long long mod=1e9+7;
long long i2=5e8+4;
int main() {
    scanf("%d",&n);
    ans=0;
    for(int i=0;i<n;i++) {
        scanf("%lld",&a[i]);
        s=(s+a[i])%mod;
        ans=(ans-a[i]*a[i])%mod;
    }
    ans=(ans+s*s)%mod;
    if(ans<0) ans+=mod;
    printf("%lld",(ans*i2)%mod);
	return 0;
}
