#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
char s[1<<16];
int a[1<<16],b[1<<16];
int f[1<<16][2];
const int MOD=998244353;
inline int add(int a,int b)
{a+=b;return a>=MOD?a-MOD:a;}
inline int sub(int a,int b)
{a-=b;return a<0?a+MOD:a;}
inline int mul(int a,int b)
{return 1LL*a*b%MOD;}
inline int ksm(int a,int b)
{
    int ans=1;
    for(;b;b>>=1,a=mul(a,a))
        if(b&1)ans=mul(ans,a);
    return ans;
}
int fac[1<<16],ifac[1<<16];
#define C(x,y) mul(fac[x],mul(ifac[x-y],ifac[y]))
int Deal(int n,int m)
{
    f[0][0]=1;
    for(int j=1;j<=m;j++){
        f[0][j&1]=mul(fac[j],fac[j]);
        for(int i=1;i<=n;i++)
            f[i][j&1]=add(mul(f[i-1][j&1],i*j),mul(f[i][j&1^1],j*j));
            //fij=fi-1j*i*j+fij-1*j^2
    }
    int als=0;
    for(int i=0;i<=n;i++)
        als=add(als,mul(f[n-i][m&1],mul(mul(fac[i],fac[i]),mul(C(n,i),C(n+m,i)))));
    return als;
}
int main()
{
    scanf("%s",s+1);
    int s1=0,s2=0,n=strlen(s+1);
    for(int i=1;i<=n;i++)
        a[i]=s[i]-'0';
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        b[i]=s[i]-'0';
    for(int i=1;i<=n;i++)
        if(a[i]+b[i]==2)++s1;
        else if(a[i])++s2;
    fac[0]=ifac[0]=1;
    for(int i=1;i<=10000;i++)
        fac[i]=mul(fac[i-1],i);
    ifac[n]=ksm(fac[n],MOD-2);
    for(int i=n-1;i;--i)
        ifac[i]=mul(ifac[i+1],i+1);
    printf("%d",Deal(s1,s2));
    return 0;
}