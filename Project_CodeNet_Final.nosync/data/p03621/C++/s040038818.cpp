#include<bits/stdc++.h>
typedef long long i64;
const int P=998244353,M=100007;
char s1[M],s2[M];
int A=0,B=0,N,K,rev[M];
i64 fac[M],fiv[M],_A[M],_B[M],E[M];
i64 pw(i64 a,i64 n){
	if(n<0)n+=P-1;
	i64 v=1;
	for(;n;n>>=1,a=a*a%P)if(n&1)v=v*a%P;
	return v;
}
void init(int mx){
	for(N=2,K=0;N<mx;N<<=1,++K);
	for(int i=1;i<N;++i)rev[i]=rev[i>>1]>>1|(i&1)<<K;
}
inline i64 fix(i64 x){return x+(x>>63&P);}
void ntt(i64*a,int t){
	for(int i=0;i<N;++i)if(i<rev[i])std::swap(a[i],a[rev[i]]);
	for(int i=1;i<N;i<<=1){
		E[0]=1;
		E[1]=pw(3,(P-1)/(i<<1)*t);
		for(int j=2;j<i;++j)E[j]=E[j-1]*E[1]%P;
		for(int j=0;j<N;j+=i<<1){
			i64*b=a+j,*c=b+i;
			for(int k=0;k<i;++k){
				i64 x=b[k],y=c[k]*E[k]%P;
				b[k]=fix(x+y-P);
				c[k]=fix(x-y);
			}
		}
	}
	if(t==-1){
		i64 I=pw(N,-1);
		for(int i=0;i<=A;++i)a[i]=a[i]*I%P;
		for(int i=A+1;i<N;++i)a[i]=0;
	}
}
void pre(){
	const int mx=1e5;
	for(int i=fac[0]=1;i<=mx;++i)fac[i]=i*fac[i-1]%P;
	fiv[mx]=pw(fac[mx],-1);
	for(int i=mx;i;--i)fiv[i-1]=i*fiv[i]%P;
}
void mul(i64*a,i64*b){
	for(int i=0;i<N;++i)a[i]=a[i]*b[i]%P;
}
int main(){
	scanf("%s%s",s1,s2);
	pre();
	for(int i=0;s1[i];++i)if(s1[i]=='1'){
		if(s2[i]=='1')++A;
		else ++B;
	}
	for(int i=0;i<=A;++i)_A[i]=fiv[i+1];
	_B[0]=1;
	init(A*2+5);
	for(int n=B;n;n>>=1){
		if(n&1)ntt(_B, 1);ntt(_A, 1);
		if(n&1)mul(_B,_A);mul(_A,_A);
		if(n&1)ntt(_B,-1);ntt(_A,-1);
	}
	i64 ans=0;
	for(int i=0;i<=A;++i)ans=fix(ans+_B[i]-P);
	ans=ans*fac[A]%P*fac[B]%P*fac[A+B]%P;
	printf("%lld\n",ans);
	return 0;
}