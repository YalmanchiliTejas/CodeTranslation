#include<cstdio>
#include<algorithm>
typedef long long LL;
const int N=32768,md=998244353;
int A,B,a[N],W[N],rev[N],lim,b[N],fac[N],iv[N],ans;
char s[N],t[N];
inline void upd(int&a){a+=a>>31&md;}
inline int pow(int a,int b){
	int ret=1;
	for(;b;b>>=1,a=(LL)a*a%md)if(b&1)ret=(LL)ret*a%md;
	return ret;
}
void init(int n){
	int l=-1;
	for(lim=1;lim<n;lim<<=1)++l;
	for(int i=1;i<lim;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<l);
}
void FFT(int*b,const int&f){
	static unsigned long long a[N];
	for(int i=0;i<lim;++i)a[i]=b[rev[i]];
	for(int i=1;i<lim;i<<=1)
	for(int j=0;j<lim;j+=i<<1)
	for(int k=0;k<i;++k){
		const unsigned long long x=a[j+k],y=a[j+k+i]*W[i+k]%md;
		a[j+k]+=y,a[j+k+i]=x+md-y;
	}
	for(int i=0;i<lim;++i)b[i]=a[i]%md;
	if(!f){
		const int iv=pow(lim,md-2);
		for(int i=0;i<lim;++i)b[i]=(LL)b[i]*iv%md;
		std::reverse(b+1,b+lim);
	}
}
void pow(int*F,int*A,int b,int n){
	FFT(F,1),FFT(A,1);
	for(;b;b>>=1){
		if(b&1){
			for(int i=0;i<lim;++i)F[i]=(LL)F[i]*A[i]%md;
			FFT(F,0);
			for(int i=n;i<lim;++i)F[i]=0;
			FFT(F,1);
		}
		for(int i=0;i<lim;++i)A[i]=(LL)A[i]*A[i]%md;
		FFT(A,0);
		for(int i=n;i<lim;++i)A[i]=0;
		FFT(A,1);
	}
	FFT(F,0);
}
int main(){
	scanf("%s%s",s,t);
	for(int i=0;s[i];++i)
	if(s[i]=='1'&&t[i]=='1')++A;else
	if(s[i]=='1'&&t[i]=='0')++B;
	for(int i=1;i<N;i<<=1){
		const int w=pow(3,(md-1)/(i<<1));
		W[i]=1;
		for(int j=1;j<i;++j)W[i+j]=(LL)W[i+j-1]*w%md;
	}
	for(int i=*fac=1;i<=A+B+1;++i)fac[i]=(LL)fac[i-1]*i%md;
	iv[A+B+1]=pow(fac[A+B+1],md-2);
	for(int i=A+B;~i;--i)iv[i]=(i+1LL)*iv[i+1]%md;
	*a=1;
	for(int i=0;i<=A;++i)b[i]=iv[i+1];
	init(A+1<<1);
	pow(a,b,B,A+1);
	for(int i=0;i<=A;++i)upd(ans+=a[i]-md);
	ans=(LL)ans*fac[A]%md*fac[B]%md*fac[A+B]%md;
	printf("%d\n",ans);
	return 0;
}