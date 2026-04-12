#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=3000;

int mod;

int add(int a,int b,int p=mod){return a+b>=p?a+b-p:a+b;}
int sub(int a,int b,int p=mod){return a-b<0?a-b+p:a-b;}
int mul(int a,int b,int p=mod){return (LL)a*b%p;}
void sadd(int &a,int b,int p=mod){a=add(a,b,p);}
void ssub(int &a,int b,int p=mod){a=sub(a,b,p);}
void smul(int &a,int b,int p=mod){a=mul(a,b,p);}
int Power(int a,int k,int p=mod){int res=1;for (;k;k>>=1,smul(a,a,p)) if (k&1) smul(res,a,p);return res;}

int n;

void into(){
  scanf("%d%d",&n,&mod);
}

int pw2[N+9];

void Get_pw2(){
  pw2[0]=1;
  for (int i=1;i<=n;++i) pw2[i]=mul(pw2[i-1],2);
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

int sl[N+9][N+9];

void Get_sl(){
  sl[0][0]=1;
  for (int i=1;i<=n+1;++i)
	for (int j=1;j<=i;++j) sl[i][j]=add(sl[i-1][j-1],mul(j,sl[i-1][j]));
}

int ans;

void Get_ans(){
  for (int i=0;i<=n;++i){
	int cnt=0,pw=1;
	for (int j=0;j<=i;++j){
	  sadd(cnt,mul(sl[i+1][j+1],pw));
	  smul(pw,pw2[n-i]);
	}
	smul(cnt,mul(Get_c(n,i),Power(2,Power(2,n-i,mod-1))));
	i&1?ssub(ans,cnt):sadd(ans,cnt);
  }
}

void work(){
  Get_pw2();
  Get_inv();
  Get_sl();
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