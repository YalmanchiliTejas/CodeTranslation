#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M=1000000007;
const int MX=200005;
ll a[MX],b[MX];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=n-1;i>=0;i--){
        b[i]=a[i]+b[i+1];
        if(b[i]>=M) b[i]-=M;
    }
    ll s=0;
    for(int i=0;i<n-1;i++){
        s+=(a[i]*b[i+1])%M;
        if(s>=M) s-=M;
    }
    printf("%lld\n",s);
    return 0;
}