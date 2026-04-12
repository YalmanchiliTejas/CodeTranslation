#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=1000010, Mod=1e9+7;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,a[N],sum;
inline int ksc(int x,int p) { int res=1; for(;p;p>>=1, x=x*x%Mod) if(p&1) res=res*x%Mod; return res; }
signed main()
{
    n=read();
    int inv2=ksc(2,Mod-2);
    for(ri int i=1;i<=n;i++) a[i]=read(), sum=(sum+a[i])%Mod;
    int res=0;
    for(ri int i=1;i<=n;i++) res=res+a[i]%Mod*(sum-a[i]+Mod)%Mod, res%=Mod;
    printf("%lld\n",res*inv2%Mod);
    return 0;
}