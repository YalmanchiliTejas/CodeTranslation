#include<bits/stdc++.h>
#define mod 1000000007
#define MN 200000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char s[MN+5];
int g[MN+5],n,m,R,all=1;
void Dp1()//每个都有一个合法相连
{
    g[1]=1;int ans=1;
    for(int i=2;i<=n;++i) g[i]=(g[i-1]+g[i-2])%mod;
    for(int i=1;i<n;++i) ans=(ans+1LL*(g[i]-g[i-1]+mod)*(n-i+1))%mod;
    printf("%d",ans);
}
void Dp2()//长度为奇数且处于[1,R]
{
    int ans=0,first=1,R=n-1;
    for(int i=1,j;i<=m;i=j)
    {
        for(j=i;j<=m&&s[j]==s[1];++j);
        if(j>m) break;
        int len=j-i;
        if(len&1) R=min(R,len);
        else first?R=min(R,len+1):0;
        first=0;
        for(;j<=m&&s[j]!=s[1];++j);
    }
    g[1]=1;
    for(int i=3;i<=n;i+=2)
    {
        g[i]=(g[i-2]-g[max(0,i-R-3)]+mod)%mod;
        g[i]=(g[i]+g[i-2])%mod;
    }
    for(int i=max(1,n-R);i<=n;i+=2) ans=(ans+1LL*(n-i+1)*(g[i]-g[max(0,i-2)]+mod))%mod;
    printf("%d",ans);
}
int main()
{
    R=n=read();m=read();scanf("%s",s+1);
    for(int i=1;i<=m;++i) if(s[i]!=s[1]) all=0;
    if(all) Dp1();
    else (n&1)?puts("0"):(Dp2(),0);
    return 0;
}