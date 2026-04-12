#include <cstdio>
#include <iostream>
typedef long long ll;

inline int Max(const int a,const int b){return a>b?a:b;}

#define pii pair<int,int>
#define fi first
#define se second

int n,h[105];
const int Mod=1000000007,Inf=0x3f3f3f3f;

ll Pow(ll a,ll b)
{
    ll s=1;
    for(;b;b>>=1,a=a*a%Mod)
        if(b&1)s=s*a%Mod;
    return s%Mod;
}

std::pair<int,int> Solve(int l,int r,int Lim)
{
    int Minh=Inf,Cnt=0;
    for(int i=l;i<=r;++i)
        if(h[i]<Minh)Minh=h[i],Cnt=1;
        else if(h[i]==Minh)++Cnt;
    if(Cnt==r-l+1)return std::make_pair(int((Pow(2,r-l+1)+Mod-2)%Mod),(int)Pow(2,Minh-Lim-1));
    int Rem=r-l+1,s0=1,s1=1,Las=0;
    for(int i=l;i<=r+1;++i)
        if(!Las&&h[i]!=Minh)Las=i;
        else if(Las&&(h[i]==Minh||i>r))
        {
            std::pair<int,int> Tmp=Solve(Las,i-1,Minh);
            s0=(ll)s0*(Tmp.first+4ll*Tmp.second%Mod)%Mod;
            s1=(ll)s1*2ll*Tmp.second%Mod,Rem-=i-Las,Las=0;
        }
    s0=(s0+Mod-s1)%Mod;
    return std::make_pair(int((s0*Pow(2,Rem)%Mod+s1*(Pow(2,Rem)+Mod-2))%Mod),int(s1*Pow(2,Minh-Lim-1)%Mod));
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&h[i]);
    if(n==1)return printf("%d\n",int(Pow(2,h[1]))),0;
    int Ex=1;
    for(int i=1;i<=n;++i)
        if(h[i]>h[i-1]&&h[i]>h[i+1])
        {
            Ex=(Ex*Pow(2,h[i]-Max(h[i-1],h[i+1])))%Mod;
            h[i]=Max(h[i-1],h[i+1]);
        }
    std::pair<int,int> Ans=Solve(1,n,0);
    printf("%d\n",int(Ex*(Ans.first+2ll*Ans.second)%Mod));
    return 0;
}
