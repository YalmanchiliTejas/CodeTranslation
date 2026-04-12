#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define pb push_back
#define fi first
#define se second
const int N=1e6+10;
const int M=1e6;
const int mod7=1e9+7;
const int mod=1e9+7;
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
void read(ll &a)
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
ll f1[N],f2[N],f3[N];
int a[N];
int main()
{
    int n;read(n);
    for(re int i=1;i<=n;i++) read(a[i]);
    if(n%2==0)
    {
        f1[1]=a[1];
        f1[2]=a[2];
        for(re int i=3;i<=n;i++)
        {
            if(i&1) f1[i]=f1[i-2]+a[i];
            else f1[i]=max(f1[i-3],f1[i-2])+a[i];
        }
        printf("%lld\n",max(f1[n-1],f1[n]));
    }
    else
    {
        f1[1]=a[1];f2[1]=a[2];f3[1]=a[3];
        for(re int i=2;i<=n/2;i++)
        {
            f1[i]=f1[i-1]+a[(i<<1)-1];
            f2[i]=max(f1[i-1],f2[i-1])+a[(i<<1)];
            f3[i]=max(f1[i-1],max(f2[i-1],f3[i-1]))+a[(i<<1)+1];
        }
        printf("%lld\n",max(f1[n/2],max(f2[n/2],f3[n/2])));
    }
    return 0;
}