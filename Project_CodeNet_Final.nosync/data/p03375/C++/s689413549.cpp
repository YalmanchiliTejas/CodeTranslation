#include<bits/stdc++.h>
#define maxn 3009
#define LL long long
using namespace std;
int C[maxn][maxn],g[maxn][maxn];
inline int qpow(int y,int mod){
  LL ans=1,x=2;
  while(y){
    if(y&1) ans=ans*x%mod;
    x=x*x%mod,y>>=1;
  }return ans;
}
int main(){
  int n,ans=0,mod;
  scanf("%d%d",&n,&mod);
  for(int i=0;i<=n;i++)
    for(int j=0;j<=i;j++)
      C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mod;
  for(int i=0;i<=n;i++) g[i][0]=1;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
      g[i][j]=((LL)g[i-1][j]*(j+1)+g[i-1][j-1])%mod;
  for(int i=0;i<=n;i++){
    int tmp=0,K=qpow(qpow(n-i,mod-1),mod);
    for(int j=0;j<=i;j++)
      tmp=((LL)g[i][j]*K%mod*qpow((n-i)*j%(mod-1),mod)+tmp)%mod;
    tmp=(LL)tmp*C[n][i]%mod;
    if(i&1) ans=(ans-tmp+mod)%mod;
    else ans=(ans+tmp)%mod;
  }
  printf("%d",ans);
  return 0;
}
