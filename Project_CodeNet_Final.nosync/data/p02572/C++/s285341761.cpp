#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int a[200005];
long long ans,sum,mod=1000000007;
long long qpow(long long a,long long b)
{
    long long p=1;
    while(b)
    {
        if(b&1) p=p*a%mod;
        b/=2;
        a=a*a%mod;
    }
    return p;
}
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) sum=(sum+a[i])%mod;
    ans=sum*sum%mod;
    for(int i=1;i<=n;i++) ans=(ans-(1LL*a[i]*a[i])%mod)%mod;
    if(ans<0) ans+=mod;
    ans=ans*(qpow(2,mod-2)%mod)%mod;
    cout<<ans<<endl;
    return 0;
}