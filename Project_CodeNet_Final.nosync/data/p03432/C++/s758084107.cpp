#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

typedef long long ll;

ll pow_mod(ll x,int k) {
  ll ans=1;
  while (k) {
  	if (k&1) ans=ans*x%MOD;
  	x=x*x%MOD;
  	k>>=1;
  }
  return ans;
}

ll facd[8005],facv[8005];

void pre(int n) {
  facd[0]=1;
  for(int i=1;i<=n;i++) facd[i]=facd[i-1]*i%MOD;
  facv[n]=pow_mod(facd[n],MOD-2);
  for(int i=n-1;i>=0;i--) facv[i]=facv[i+1]*(i+1)%MOD;
}

inline ll C(int n,int m) {
  return (n<m)?0:facd[n]*facv[m]%MOD*facv[n-m]%MOD;
}

const int Maxn=1<<14;

ll *w[14];

void ntt_init() {
  for(int i=2,t=1;i<=Maxn;i<<=1,t++) {
  	w[t]=new ll[i>>1];
  	ll wn=pow_mod(3,(MOD-1)/i);
  	w[t][0]=1;
  	for(int j=1;j<(i>>1);j++) w[t][j]=w[t][j-1]*wn%MOD;
  }
}

void rev(ll *p,int len) {
  int j=len>>1;
  for(int i=1;i<len-1;i++) {
  	if (i<j) swap(p[i],p[j]);
  	int k=len>>1;
  	while (j>=k) {
  		j-=k;
  		k>>=1;
	  }
	if (j<k) j+=k;
  }
}

void ntt(ll *p,int len,int check) {
  rev(p,len);
  for(int i=2,t=1;i<=len;i<<=1,t++)
    for(int j=0;j<len;j+=i)
      for(int k=j;k<j+(i>>1);k++) {
      	ll u=p[k];
      	ll v=w[t][k-j]*p[k+(i>>1)];
      	p[k]=(u+v)%MOD;
      	p[k+(i>>1)]=(u-v)%MOD;
	  }
  if (check==-1) {
  	reverse(p+1,p+len);
  	ll nev=pow_mod(len,MOD-2);
  	for(int i=0;i<len;i++) p[i]=(p[i]+MOD)*nev%MOD;
  }
}

int f[2][8005],cur;

inline void update(int &x,ll y) {
  x=(x+y)%MOD;
}

inline ll S(int n) {
  return n*(n-1)>>1;
}

void dp(int n) {
  static ll p[Maxn],q[Maxn];
  cur^=1;
  memset(f[cur],0,sizeof(f[cur]));
  for(int i=0;i<=n;i++) update(f[cur][i],f[cur^1][i]*(S(i+1)+1));
  int len=1;
  while (len<((n+1)<<1)) len<<=1;
  memset(p,0,sizeof(ll)*len);
  memset(q,0,sizeof(ll)*len);
  for(int i=0;i<=n;i++) p[i]=f[cur^1][i]*facv[i]%MOD;
  for(int i=1;i<=n;i++) q[i]=facv[i+2];
  ntt(p,len,1);
  ntt(q,len,1);
  for(int i=0;i<len;i++) p[i]=p[i]*q[i]%MOD;
  ntt(p,len,-1);
  for(int i=1;i<=n;i++) update(f[cur][i],p[i]*facd[i+2]);
}

int main() {
  ntt_init();
  int n,m;
  scanf("%d%d",&n,&m);
  pre(n+2);
  f[0][0]=1;
  for(int i=1;i<=m;i++) dp(n);
  int ans=0;
  for(int i=0;i<=n;i++) update(ans,f[cur][i]*C(n,i));
  printf("%d\n",ans);
  return 0;
}