#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<bitset>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
inline int read(){
    int f=1,ans=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
    return f*ans;
}
const int MAXN=3011;
int f[MAXN][MAXN],fac[MAXN],pw2[MAXN],pw22[MAXN],ifac[MAXN],inv[MAXN],N,mod,F[MAXN],Ans,pw=-1;
int ksm(int a,int b){int ans=1;while(b){if(b&1) ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;}
int C(int a,int b){return fac[a]*ifac[b]%mod*ifac[a-b]%mod;}
signed main(){
    N=read(),mod=read();fac[0]=fac[1]=ifac[0]=ifac[1]=inv[1]=1;pw2[0]=pw22[0]=1;for(int i=1;i<MAXN;i++) pw2[i]=pw2[i-1]*2%mod,pw22[i]=pw22[i-1]*2%(mod-1);
    for(int i=2;i<MAXN;i++) fac[i]=fac[i-1]*i%mod,inv[i]=(mod-mod/i)*inv[mod%i]%mod,ifac[i]=ifac[i-1]*inv[i]%mod;
    f[0][0]=1;for(int i=1;i<MAXN;i++){for(int j=1;j<=i;j++) f[i][j]=f[i-1][j-1]+j*f[i-1][j],f[i][j]%=mod;}
    for(int i=0;i<=N;i++) for(int j=0;j<=i;j++) {F[i]+=C(N,i)*f[i+1][j+1]%mod*ksm(2,pw22[N-i])%mod*ksm(pw2[N-i],j)%mod,F[i]%=mod;}
    for(int i=0;i<=N;i++) pw*=-1,Ans=(Ans+pw*F[i]+mod)%mod;
    printf("%lld\n",Ans);return 0;
}
