#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
#define ll long long 
#define il inline
const int maxn=200010;
const ll mod=1e9+7;
ll a[maxn],s[maxn];
int n; ll ans=0;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        s[i]=(s[i-1]+a[i])%mod;
    }
    for (int i=n;i>=2;--i){
        ans=(ans+(s[i-1]*a[i])%mod)%mod;
    }
    printf("%lld",ans);
}