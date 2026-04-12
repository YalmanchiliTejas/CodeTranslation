#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD=998244353;
int fac[10001],inv[10001];
long long qpow(long long a,int b)
{
    long long ret=1;
    for (;b;(a*=a)%=MOD,b>>=1)
        if (b&1)
            (ret*=a)%=MOD;
    return ret;
}
void ntt(vector<int> &src,int bits,bool rev)
{
    for (int i=0;i<(1<<bits);++i)
    {
        int t=i,rev=0;
        for (int j=0;j<bits;++j)
        {
            (rev<<=1)^=t&1;
            t>>=1;
        }
        if (rev>i)
            swap(src[i],src[rev]);
    }
    for (int i=2;i<=(1<<bits);i<<=1)
    {
        int w=qpow(3,(MOD-1)/i);
        if (rev)
            w=qpow(w,MOD-2);
        for (int j=0;j<(1<<bits);j+=i)
        {
            int cur=1;
            for (int k=j;k<j+i/2;++k)
            {
                int v2=(long long)src[k+i/2]*cur%MOD;
                src[k+i/2]=src[k]-v2;
                if (src[k+i/2]<0)
                    src[k+i/2]+=MOD;
                src[k]+=v2;
                if (src[k]>=MOD)
                    src[k]-=MOD;
                cur=(long long)cur*w%MOD;
            }
        }
    }
    if (rev)
    {
        int inv=qpow(1<<bits,MOD-2);
        for (int i=0;i<(1<<bits);++i)
            src[i]=(long long)src[i]*inv%MOD;
    }
}
vector<int> polynomial_pow(vector<int> base,int p,int reserved_len)
{
    int bits=0;
    while ((1<<bits)<(reserved_len+reserved_len+1))
        ++bits;
    base.resize(1<<bits);
    for (size_t i=reserved_len+1;i<base.size();++i)
        base[i]=0;
    vector<int> ret(1<<bits);
    ret[0]=1;
    while (p)
    {
        ntt(base,bits,0);
        if (p&1)
        {
            ntt(ret,bits,0);
            for (int i=0;i<(1<<bits);++i)
                ret[i]=(long long)ret[i]*base[i]%MOD;
            ntt(ret,bits,1);
            for (size_t i=reserved_len+1;i<ret.size();++i)
                ret[i]=0;
        }
        for (int i=0;i<(1<<bits);++i)
            base[i]=(long long)base[i]*base[i]%MOD;
        ntt(base,bits,1);
        for (size_t i=reserved_len+1;i<base.size();++i)
            base[i]=0;
        p>>=1;
    }
    ret.resize(reserved_len+1);
    return ret;
}
char s1[10001],s2[10001];
int binomial_coefficient(int a,int b)
{
    return (long long)fac[a]*inv[b]%MOD*inv[a-b]%MOD;
}
int main()
{
    fac[0]=inv[0]=fac[1]=inv[1]=1;
    for (int i=2;i<=10000;++i)
    {
        fac[i]=(long long)fac[i-1]*i%MOD;
        inv[i]=MOD-(long long)MOD/i*inv[MOD%i]%MOD;
    }
    for (int i=2;i<=10000;++i)
        inv[i]=(long long)inv[i-1]*inv[i]%MOD;
    scanf("%s%s",s1,s2);
    int n=strlen(s1),only=0,both=0;
    for (int i=0;i<n;++i)
        if (s1[i]=='1')
            (s2[i]=='0'?only:both)+=1;
    vector<int> dp(only+both+1);
    for (int i=1;i<=only+both;++i)
        dp[i]=inv[i];
    dp=polynomial_pow(dp,only,only+both);
    int ans=0;
    for (int i=0;i<=both;++i)
    {
        ans+=(long long)binomial_coefficient(only+both,only+i)*fac[both-i]%MOD*fac[both-i]%MOD*binomial_coefficient(both,i)%MOD*fac[i]%MOD*fac[only+i]%MOD*dp[only+i]%MOD*fac[only]%MOD;
        if (ans>=MOD)
            ans-=MOD;
    }
    printf("%d\n",ans);
    return 0;
}
