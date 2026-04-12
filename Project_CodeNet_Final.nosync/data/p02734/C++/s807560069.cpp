#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define re register
#define pb push_back
#define fi first
#define se second
#define mp make_pair
const int N=2e6+10;
const int mod=998244353;
const int mod2=19260811;
void read(int &a)
{
    a=0;int d=1;char ch;
    while(ch=getchar(),ch>'9'||ch<'0')
        if(ch=='-')
            d=-1;
    a=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9')
        a=(a<<3)+(a<<1)+(ch^48);
    a*=d;
}
int f[N];
int main()
{
    int n,m,ans=0;
    read(n),read(m);
    for(re int i=1,x;i<=n;i++)
    {
        f[0]++;read(x);
        for(re int j=m;j>=x;j--)
        {
            f[j]+=f[j-x];
            f[j]%=mod;
        }
        ans+=f[m];
        ans%=mod;
    }
    printf("%d",ans);
    return 0;
}