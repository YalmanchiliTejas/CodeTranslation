#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e7+7,mo=998244353;
inline int fk(int x) { return x>=mo ? x-mo : x; }
int n,fac[N],facinv[N];
int ksm(int x,int y)
{
    int res=1;
    while(y) { if(y&1) res=1ll*res*x%mo; x=1ll*x*x%mo; y>>=1; }
    return res;
}
inline int C(int x,int y) { return 1ll*fac[x]*facinv[y]%mo*facinv[x-y]%mo; }
int main()
{
    cin>>n;
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mo;
    facinv[n]=ksm(fac[n],mo-2);
    for(int i=n-1;i>=0;i--) facinv[i]=1ll*facinv[i+1]*(i+1)%mo;
    int ans=ksm(3,n);
    for(int k=n/2+1;k<=n;k++)
        ans=fk(ans-2ll*C(n,k)*ksm(2,n-k)%mo+mo);
    cout<<ans<<endl;
    return 0;
}