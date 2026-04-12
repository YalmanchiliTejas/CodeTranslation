#include<cstdio>
typedef long long ll;
const int N=8024,D=203,M=998244353,G=3,K=14;
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
int n,m,f[N],fac[N],invf[N],ans,a[1<<K],b[1<<K],rev[1<<K];
inline int C(int n,int m){
	if(n<m||m<0)return 0;
	return(ll)fac[n]*invf[m]%M*invf[n-m]%M;
}
inline void Init(){
	for(int i=0;i<(1<<K);i++)rev[i]=rev[i>>1]>>1|(i&1)<<K-1;
}
inline void Ntt(int*a,int f){
	int tmp,s,w;
	for(int i=0;i<(1<<K);i++)if(i<rev[i])
	  tmp=a[i],a[i]=a[rev[i]],a[rev[i]]=tmp;
	for(int k=1;k<(1<<K);k<<=1){
	  w=Pow(G,f>0?M/2/k:M-1-M/2/k);
	  for(int i=0;i<(1<<K);i+=k+k){
		s=1;
		for(int j=0;j<k;j++,s=(ll)s*w%M){
		  tmp=(ll)s*a[i+k+j]%M;
		  (a[i+k+j]=a[i+j]-tmp)<0&&(a[i+k+j]+=M);
		  (a[i+j]+=tmp)>=M&&(a[i+j]-=M);
		}
	  }
	}
	if(f<0){
	  tmp=Pow(1<<K,M-2);
	  for(int i=0;i<(1<<K);i++)a[i]=(ll)a[i]*tmp%M;
	}
}
int main(){
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=(ll)fac[i-1]*i%M;
	invf[N-1]=Pow(fac[N-1],M-2);
	for(int i=N-1;i;i--)invf[i-1]=(ll)invf[i]*i%M;
	scanf("%d%d",&n,&m);
	Init();
	for(int i=1;i<=n;i++)b[i]=invf[i+2];
	Ntt(b,1);
	f[0]=1;
	for(int j=1;j<=m;j++){
	  for(int i=0;i<(1<<K);i++)a[i]=0;
	  for(int i=0;i<=n;i++)a[i]=(ll)f[i]*invf[i]%M;
	  Ntt(a,1);
	  for(int i=0;i<(1<<K);i++)a[i]=(ll)a[i]*b[i]%M;
	  Ntt(a,-1);
	  for(int i=0;i<=n;i++)f[i]=((ll)f[i]*(C(i,2)+i+1)+(ll)fac[i+2]*a[i])%M;
	}
	for(int k=0;k<=n;k++)
	  ans=(ans+(ll)f[k]*C(n,k))%M;
	printf("%d\n",ans);
	return 0;
}