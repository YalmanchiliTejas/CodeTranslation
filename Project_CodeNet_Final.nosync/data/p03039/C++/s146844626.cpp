#include<bits/stdc++.h>
using namespace std;
#define Mod 1000000007
#define N 200010
#define LL long long
LL a[N],b[N];
LL find(LL x,LL y)
{
    LL ans=1;
    x=x%Mod;
    while(y)
    {
        if(y%2)
            ans=ans*x%Mod;
        x=x*x%Mod;
        y=y/2;
    }
    return ans;
}
LL C(int x,int y)
{
    if(x<y)
        return 0;
    return a[x]*b[y]%Mod*b[x-y]%Mod;
}
int main()
{
    int i,j,k,n,m,d;
    LL ans;
    scanf("%d%d%d",&n,&m,&d);
    a[0]=1;
    for(i=1;i<=200000;i++)
        a[i]=a[i-1]*i%Mod;
    b[200000]=find(a[200000],Mod-2);
    for(i=200000;i>=1;i--)
        b[i-1]=b[i]*i%Mod;
    ans=C(n*m,d)*C(d,2)%Mod*(n+m)%Mod*find(3,Mod-2)%Mod;
    printf("%lld\n",ans);
    return 0;
}