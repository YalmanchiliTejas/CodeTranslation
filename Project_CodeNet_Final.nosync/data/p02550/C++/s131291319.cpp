#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000;

LL n;
int mod,x;
int nxt[N+9];
int p[N+9],a[N+9];
LL sum[N+9],ans;

void work(){
  scanf("%lld%d%d",&n,&x,&mod);
  int now=x;
  for (int i=0;i<mod;++i) nxt[i]=1LL*i*i%mod;
  if (n==1) {printf("%d\n",x);return;}
  p[sum[1]=a[1]=x]=1;
  for (int i=2;i<=mod+2;++i){
	a[i]=nxt[a[i-1]];
	sum[i]=sum[i-1]+a[i];
	if (i==n) {printf("%lld\n",sum[i]);return;}
	if (p[a[i]]){
	  ans=sum[i];
	  int c=i-p[a[i]];
	  n-=i;
	  ans+=(sum[i]-sum[p[a[i]]])*(n/c);
	  //printf("%lld\n",sum[i]-sum[p[a[i]]-1]);
	  n%=c;
	  int now=a[i];
	  for (int j=1;j<=n;++j) ans+=now=nxt[now];
	  printf("%lld\n",ans);
	  return;
	}
	p[a[i]]=i;
  }
}

int main(){
  int T=1;
  for (;T--;) work();
  return 0;
}