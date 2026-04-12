#include<bits/stdc++.h>
#define re register
#define inc(i,j,k) for(re int i=j;i<=k;i++)
#define ll long long
using namespace std;
const int N=3005;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,m;
ll s[N][N],c[N][N],ans;
ll qp(ll x,ll k,ll mod){
	ll res=1;
	while(k){
		if(k&1) res=res*x%mod;
		k>>=1,x=x*x%mod;
	}
	return res;
}
int main(){
	n=read(),m=read();
	s[0][0]=1;
	inc(i,0,n+1){
		c[i][0]=1;
		inc(j,1,i) s[i][j]=(s[i-1][j-1]+j*s[i-1][j])%m,c[i][j]=(c[i-1][j]+c[i-1][j-1])%m;
	}
	inc(i,0,n){
		ll tmp=0;
		inc(j,0,i) (tmp+=s[i+1][j+1]*qp(2,j*(n-i),m)%m)%=m;
		tmp=tmp*qp(2,qp(2,n-i,m-1),m)%m*c[n][i]%m;
		(ans+=(i&1)?m-tmp:tmp)%=m;
	}
	printf("%lld",ans);
}
 