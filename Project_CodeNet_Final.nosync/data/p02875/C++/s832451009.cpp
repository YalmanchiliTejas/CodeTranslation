#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=10000000,mod=998244353;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int add(int a,int b,int p=mod){return a+b>=p?a+b-p:a+b;}
int sub(int a,int b,int p=mod){return a-b<0?a-b+p:a-b;}
int mul(int a,int b,int p=mod){return (LL)a*b%p;}
void sadd(int &a,int b,int p=mod){a=add(a,b,p);}
void ssub(int &a,int b,int p=mod){a=sub(a,b,p);}
void smul(int &a,int b,int p=mod){a=mul(a,b,p);}

int n;

void into(){
  scanf("%d",&n);
}

int inv[N+9],fac[N+9],ifac[N+9];

void Get_inv(){
  inv[1]=1;
  fac[0]=fac[1]=1;
  ifac[0]=ifac[1]=1;
  for (int i=2;i<=n;++i){
	inv[i]=mul(mod-mod/i,inv[mod%i]);
	fac[i]=mul(fac[i-1],i);
	ifac[i]=mul(ifac[i-1],inv[i]);
  }
}

int Get_c(int n,int m){return n<m||m<0?0:mul(fac[n],mul(ifac[m],ifac[n-m]));}

int ans;

void Get_ans(){
  ans=1;
  for (int i=1;i<=n;++i) smul(ans,3);
  int pw=2;
  for (int i=n;i>=n+2>>1;--i) ssub(ans,mul(pw,Get_c(n,i))),smul(pw,2);
}

void work(){
  Get_inv();
  Get_ans();
}

void outo(){
  printf("%d\n",ans);
}

int main(){
  into();
  work();
  outo();
  return 0;
}