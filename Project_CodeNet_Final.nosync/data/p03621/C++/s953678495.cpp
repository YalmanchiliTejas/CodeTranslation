#include <bits/stdc++.h>
#define ysf (998244353)
#define N (10005)
int f[N][N],fac[N],ifac[N],inv[N],n,x,y,ans;
char a[N],b[N];
inline int C(int n,int m){
  return 1LL*fac[n]*ifac[m]%ysf*ifac[n-m]%ysf;
}
int main(){
  scanf("%s%s",a+1,b+1),n=strlen(a+1),f[0][0]=fac[0]=ifac[0]=1;
  for (int i=1;i<=n;++i) if (a[i]=='1') x+=b[i]=='1',y+=b[i]=='0';
  for (int i=1;i<=x+y;++i){
    inv[i]=i==1 ? 1 : 1LL*(ysf-ysf/i)*inv[ysf%i]%ysf;
    fac[i]=1LL*fac[i-1]*i%ysf,ifac[i]=1LL*ifac[i-1]*inv[i]%ysf;
  }
  for (int i=0;i<=x;++i)
    for (int j=0;j<=y;++j){
      if (i) f[i][j]=1LL*f[i-1][j]*i*j%ysf;
      if (j) f[i][j]=(f[i][j]+1LL*f[i][j-1]*j*j)%ysf;
    }
  for (int i=0;i<=x;++i)
    ans=(ans+1LL*fac[i]*fac[i]%ysf*C(x,i)%ysf*C(x+y,i)%ysf*f[x-i][y])%ysf;
  std::cout<<ans; return 0;
}
