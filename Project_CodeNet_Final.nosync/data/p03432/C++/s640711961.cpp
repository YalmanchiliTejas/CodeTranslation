#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
const int N=2e4+5;
int n,m,k,len,r[N];
long long ans,Inv,f[N],g[N],h[N],fac[N],inv[N];
long long fsp(long long x,int y){
	long long ans=1;
	while(y){
		if(y&1)	ans=ans*x%P;
		y>>=1,x=x*x%P;
	}
	return ans;
}
void NTT(long long *d,int f){
	for(int i=1;i<n;i++)	if(i<r[i])	swap(d[i],d[r[i]]);
	for(int i=1;i<n;i<<=1){
		int wn=fsp(3,(P-1)/(i<<1));
		if(f)	wn=fsp(wn,P-2);
		for(int j=0;j<n;j+=i<<1){
			long long w=1;
			for(int k=0;k<i;k++,w=w*wn%P){
				int x=d[j+k],y=w*d[i+j+k]%P;
				d[j+k]=(x+y)%P,d[i+j+k]=(x-y+P)%P;
			}
		}
	}
	if(f)	for(int i=0;i<n;i++)	d[i]=d[i]*Inv%P;
}
long long C(int n,int m){
	return fac[n]*inv[m]%P*inv[n-m]%P;
}
int main(){
	scanf("%d%d",&k,&m),fac[0]=inv[0]=1;
	for(int i=1;i<=k+2;i++){
		fac[i]=fac[i-1]*i%P;
		inv[i]=fsp(fac[i],P-2);
	}
	for(;(1<<len)<=k*2;++len);
	n=1<<len,Inv=fsp(n,P-2),g[0]=1;
	for(int i=1;i<=k;i++)	h[i]=inv[i+2];
	for(int i=1;i<n;i++)	r[i]=(r[i>>1]>>1)|((i&1)<<(len-1));
	NTT(h,0);

	while(m--){
		for(int i=0;i<=k;i++)	f[i]=(1LL*i*(i-1)/2+i+1)*g[i]%P;
		for(int i=0;i<=k;i++)	g[i]=g[i]*inv[i]%P;
		NTT(g,0);

		for(int i=0;i<n;i++)	g[i]=g[i]*h[i]%P;

		NTT(g,1);
		for(int i=k+1;i<n;i++)	f[i]=0;
		for(int i=0;i<=k;i++)	f[i]=(f[i]+g[i]*fac[i+2])%P;
		swap(f,g);
	}
	for(int i=0;i<=k;i++)	ans=(ans+g[i]*C(k,i))%P;
	printf("%lld\n",ans);
	return 0;
}
