#include<cstdio>
const int mod=998244353;
int fac[8010],ifac[1<<14],f[1<<14],g[8010];
int pw(int a,int n=mod-2){int b=1;for(;n;n>>=1)n&1?b=1ll*b*a%mod:1,a=1ll*a*a%mod;return b;}
int C(int n,int m){return m<0||m>n?0:1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int ws[1<<14];
void dft(int*a,int n,bool r=0){
	int*w=ws+n/2;
	*w=1;w[1]=pw(3,(mod-1)/n);
	if(r)w[1]=pw(w[1]);
	for(int i=2;i<n/2;i++)w[i]=1ll*w[i-1]*w[1]%mod;
	for(int i=n/2;--i;)ws[i]=ws[i*2];
	w=ws+1;
	for(int i=0,j=0,t;i<n;i++){
		if(i<j)t=a[i],a[i]=a[j],a[j]=t;
		for(t=n/2;(j^=t)<t;t/=2);
	}
	for(int i=1;i<n;w+=i,i*=2){
		for(int j=0;j<n;j+=i*2){
			for(int k=0,t;k<i;k++){
				t=1ll*a[i+j+k]*w[k]%mod;
				a[i+j+k]=(a[j+k]+mod-t)%mod;
				a[j+k]=(a[j+k]+t)%mod;
			}
		}
	}
	if(r){
		long long I=pw(n);
		for(int i=0;i<n;i++)a[i]=a[i]*I%mod;
	}
}
int main(){
	int N,M;scanf("%d%d",&N,&M);
	for(int i=*fac=1;i<=N+2;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[N]=pw(fac[N+2]);
	for(int i=N;i>1;i--)ifac[i-1]=ifac[i]*(i+2ll)%mod;
	int n=1;while(n<=N*2)n*=2;
	dft(ifac,n);
	*f=1;
	for(int i=0;i<M;i++){
		for(int j=0;j<=N;j++)g[j]=f[j]*(j*(j+1)/2+1ll)%mod;
		dft(f,n);
		for(int j=0;j<n;j++)f[j]=1ll*f[j]*ifac[j]%mod;
		dft(f,n,1);
		for(int j=0;j<n;j++)f[j]=j>N?0:(f[j]*((j+2)*(j+1ll))+g[j])%mod;
	}
	int s=0;
	for(int i=0,w=1;i<=N;i++,w=w*(N-i+1ll)%mod)s=(s+1ll*w*f[i])%mod;
	printf("%d\n",s);
}