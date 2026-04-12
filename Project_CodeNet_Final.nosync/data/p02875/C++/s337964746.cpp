#include <bits/stdc++.h>
#define FR first
#define SE second
#define MOD 998244353
#define inv4 748683265

using namespace std;

typedef long long ll;
typedef pair<int,int> pr;

ll pow_mod(ll x,int k) {
  ll ans=1;
  while (k) {
  	if (k&1) ans=ans*x%MOD;
  	x=x*x%MOD;
  	k>>=1;
  }
  return ans;
}

const int Maxn=5000000+5;

int facd[Maxn],facv[Maxn];

void pre(int n) {
  facd[0]=1;
  for(int i=1;i<=n;i++) facd[i]=(ll)facd[i-1]*i%MOD;
  facv[n]=pow_mod(facd[n],MOD-2);
  for(int i=n-1;i>=0;i--) facv[i]=(ll)facv[i+1]*(i+1)%MOD;
}

inline ll C(int n,int m) {
  return (n<m)?0:(ll)facd[n]*facv[m]%MOD*facv[n-m]%MOD;
}

int main() {
  int n;
  scanf("%d",&n);
  n>>=1;
  pre(n);
  int ans=1;
  for(int i=1;i<=n;i++) ans=ans*9LL%MOD;
  ll s1=0,s2=inv4,s3=pow_mod(4LL,n);
  for(int i=1;i<=n;i++) {
  	if (i>1) s1=(s1+(s1-C(i-1,(i-2)>>1)*s2)*4LL)%MOD;
  	if (i&1) {
	  s2=s2*4LL%MOD;
	  s1=(s1+C(i,i>>1)*s2)%MOD;
    }
    s3=s3*inv4%MOD;
    ans=(ans-2LL*s3*C(n,i)%MOD*s1)%MOD;
  }
  printf("%d\n",(ans+MOD)%MOD);
  return 0;
} 