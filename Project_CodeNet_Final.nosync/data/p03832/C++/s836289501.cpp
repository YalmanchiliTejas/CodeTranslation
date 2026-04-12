#include <iostream>

using namespace std;
int n,a,b,c,d;
long long fac[1010],f[1010][1010],rev[1010],mod=1e9+7;

long long exp(long long v,int k)
{
    long long ret=1;
    while (k)
    {
        if (k%2)
            ret*=v,ret%=mod;
        k/=2;
        v*=v;
        v%=mod;
    }
    return ret;
}

int main()
{
    cin >> n >> a >>b >> c >>d;
    fac[0]=rev[0]=1;
    for (long long i=1;i<1010;i++)
        fac[i]=fac[i-1]*i,fac[i]%=mod,rev[i]=rev[i-1]*exp(i,mod-2),rev[i]%=mod;
    f[0][0]=1;
    for (int i=0;i<=b-a;i++)
    {
        for (int j=0;j<=n;j++)
        {
            f[i+1][j]+=f[i][j];
            f[i+1][j]%=mod;
            int cur=c*(a+i),ti=c;
            while (j+cur<=n and cur<=d*(a+i))
            {
                f[i+1][j+cur]+=((((f[i][j]*fac[j+cur])%mod*rev[j])%mod*exp(rev[a+i],ti))%mod*rev[ti])%mod;
                f[i+1][j+cur]%=mod;
                cur+=a+i,ti++;
            }
        }
    }
    cout << f[b-a+1][n] << "\n";
}
