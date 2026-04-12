#include<bits/stdc++.h>
#define MN 100
#define mod 1000000007
#define MK 32768
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,a[MN+5],L[MN+5],num,f[MN+5][MN+5],pw[MK+5],PW[MK+5],ans;
inline void R(int&x,int y){(x+=y)>=mod?x-=mod:0;}
inline int pw2(int x){return 1LL*PW[x>>15]*pw[x&32767]%mod;}
inline int Sum(int l,int r){return (pw2(r+1)-pw2(l)+mod)%mod;}
int main()
{   
    n=read();pw[0]=PW[0]=1;
    for(int i=1;i<=MK;++i) pw[i]=2*pw[i-1]%mod;
    for(int i=1;i<=MK;++i) PW[i]=1LL*PW[i-1]*pw[MK]%mod;
    for(int i=1;i<=n;++i) a[i]=L[i]=read();
    sort(L+1,L+n+1);num=unique(L+1,L+n+1)-L-1;L[++num]=2e9;
    f[0][num]=1;
    for(int i=1;i<=n;++i)
    {
        a[i]=lower_bound(L+1,L+num+1,a[i])-L;
        for(int j=1;j<=a[i];++j) R(f[i][j],1LL*f[i-1][j]*pw2(max(0,L[a[i]]-L[a[i-1]]))%mod);
        int res=0;
        for(int j=a[i]+1;j<=num;++j) R(res,f[i-1][j]);
        res=2*res%mod;
        for(int j=a[i-1]+1;j<=a[i];++j) 
        {
            int l=max(2,L[j-1]+1),r=L[j];if(l>r) continue;
            R(f[i][j],1LL*res*Sum(L[a[i]]-r,L[a[i]]-l)%mod);  
        }
        R(f[i][num],res);
    }
    for(int j=1;j<=num;++j) R(ans,f[n][j]);
    cout<<ans;
    return 0;
}