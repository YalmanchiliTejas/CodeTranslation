#include <cstdio>
#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

const int N=3010;

int n,P,fac[N],inv[N],f[N][N];

inline void Pre(const int &n){
  fac[0]=1; for(int i=1;i<=n;i++) fac[i]=1LL*fac[i-1]*i%P;
  inv[1]=1; for(int i=2;i<=n;i++) inv[i]=1LL*(P-P/i)*inv[P%i]%P;
  inv[0]=1; for(int i=1;i<=n;i++) inv[i]=1LL*inv[i-1]*inv[i]%P;
}

inline int C(int x,int y){
  if(x==-1 && y==-1) return 1;
  return 1LL*fac[x]*inv[y]%P*inv[x-y]%P;
}

inline int Pow(int x,int y,int p=P){
  int ret=1;
  for(;y;y>>=1,x=1LL*x*x%p) if(y&1) ret=1LL*ret*x%p;
  return ret;
}

int main(){
#ifdef ljn
  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
#endif
  cin>>n>>P; Pre(3000);
  int ans=0;
  f[0][0]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++)
      f[i][j]=(f[i-1][j-1]+1LL*j*f[i-1][j])%P;
  }
  
  for(int i=0;i<=n;i++){
    int cur=1,t=Pow(2,n-i);
    /*for(int j=1;j<=i;j++){
      int c=0;
      //c=Pow(t,j);
      for(int k=1;k<=j;k++)
	c=(c+1LL*f[j][k]*Pow(t,k))%P;
      cur=(cur+1LL*c*C(i,j))%P;
    }
    */
    for(int k=1;k<=i;k++){
      int c=(f[i][k]+1LL*f[i][k+1]*C(k+1,k))%P;
      //for(int j=k;j<=i;j++)
      //c=(c+1LL*f[j][k]*C(i,j))%P;
      assert(c==(f[i][k]+1LL*f[i][k+1]*C(k+1,k))%P);
      cur=(cur+1LL*Pow(t,k)*c)%P;
    }
    //for(int k=1;k<=i;k++)
    //  c=(c+1LL*Pow(t,k)*(f[n][k]-f[k-1][k]))%P;
    cur=1LL*cur*C(n,i)%P*Pow(2,Pow(2,n-i,P-1))%P;
    if(i&1) ans=(ans-cur)%P;
    else ans=(ans+cur)%P;
  }
  printf("%d\n",(ans+P)%P);
  return 0;
}
 
