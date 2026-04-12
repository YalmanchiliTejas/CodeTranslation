#include<cstdio>
#include<algorithm>
using namespace std;
const int N=20005;
const int mod=998244353;
int n,m,jc[N],jcn[N],len=1,l,rev[N],w[N],f[N],g[N],tmp[N],ans;
void Inc(int &x,int y){
	x+=y;x>=mod?x-=mod:x;
}
int C(int x,int y){
	return 1ll*jc[x]*jcn[y]%mod*jcn[x-y]%mod;
}
int fastpow(int x,int y){
	int res=1;
	while(y){if(y&1)res=1ll*res*x%mod;x=1ll*x*x%mod;y>>=1;}
	return res;
}
void ntt(int *p,int op){
	for(int i=0;i<len;++i)if(i<rev[i])swap(p[i],p[rev[i]]);
	for(int i=1,t=1;i<len;i<<=1,++t)
		for(int j=0;j<len;j+=i<<1)
			for(int k=0;k<i;++k){
				int x=1ll*w[(len>>t)*k]*p[j+k+i]%mod;
				p[j+k+i]=p[j+k];
				Inc(p[j+k],x);Inc(p[j+k+i],mod-x);
			}
	if(op==-1){
		reverse(p+1,p+len);int inv_len=fastpow(len,mod-2);
		for(int i=0;i<len;++i)p[i]=1ll*p[i]*inv_len%mod;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	jc[0]=1;
	for(int i=1;i<N;++i)jc[i]=1ll*jc[i-1]*i%mod;
	jcn[N-1]=fastpow(jc[N-1],mod-2);
	for(int i=N-1;i;--i)jcn[i-1]=1ll*jcn[i]*i%mod;
	while(len<=n+n)len<<=1,++l;
	for(int i=0;i<len;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<l-1);
	w[0]=1;w[1]=fastpow(3,mod>>l);
	for(int i=2;i<len;++i)w[i]=1ll*w[i-1]*w[1]%mod;
	for(int i=1;i<=n;++i)g[i]=jcn[i+2];
	ntt(g,1);f[0]=1;
	for(int i=1;i<=m;++i){
		for(int j=0;j<=n;++j)tmp[j]=f[j],f[j]=1ll*f[j]*jcn[j]%mod;
		ntt(f,1);
		for(int j=0;j<len;++j)f[j]=1ll*f[j]*g[j]%mod;
		ntt(f,-1);
		for(int j=0;j<=n;++j)f[j]=(1ll*f[j]*jc[j+2]+1ll*tmp[j]*(1+C(j+1,2)))%mod;
		for(int j=n+1;j<len;++j)f[j]=0;
	}
	for(int i=0;i<=n;++i)ans=(ans+1ll*f[i]*C(n,i))%mod;
	printf("%d\n",ans);return 0;
}
