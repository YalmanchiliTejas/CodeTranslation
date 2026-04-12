#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 3010;
inline LL read()
{
  LL p=0; LL f=1; char ch=getchar();
  while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
  while(ch>='0' && ch<='9'){p=p*10+ch-'0'; ch=getchar();}
  return p*f;
}
LL C[N][N],S[N][N];
LL qpow(LL x,LL k,LL mo){LL s=1; while(k){if(k&1) s=s*x%mo; x=x*x%mo; k>>=1;} return s;}
int main()
{
  LL n = read(); LL p = read();
  C[0][0] = 1; for(LL i=1;i<=n+1;i++)
  {
  	C[i][0] = 1; for(LL j=1;j<=i;j++) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % p;
  }
  S[0][0] = 1; for(LL i=1;i<=n+1;i++)
  {
    S[i][1] = 1; for(LL j=2;j<=i;j++) S[i][j] = (S[i-1][j] * j + S[i-1][j-1]) % p;
  }
  
  LL ans = 0;
  for(LL i=0;i<=n;i++)
  {
    LL s = C[n][i] * qpow(2,qpow(2,n-i,p-1),p) % p;
    LL fr = 0; for(LL j=0;j<=i;j++) fr = (fr + qpow(2,(n-i)*j%(p-1),p) * S[i+1][j+1] % p) % p;
    // printf("%lld %lld\n",s,fr);
    ans =( (ans + ((i&1) ? (-1) : 1) * s % p * fr % p ) % p + p ) % p;
  }
  return printf("%lld\n",ans),0;
}