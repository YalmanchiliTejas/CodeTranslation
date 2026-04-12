#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
const int mod=998244353;
const int M=14;
int n,m,ans,f[8010],F[8010];
int r[1<<M],A[1<<M],B[1<<M],a[1<<M],b[1<<M];
void inc(int &a,int b){
	(a+=b)%=mod;
}
int C(int n,int m){
	if(n<m||n<0||m<0)return 0;
	return 1LL*f[n]*F[m]%mod*F[n-m]%mod;
}
int mi(int a,int b){
	int s=1;
	for(;b;b>>=1,a=1LL*a*a%mod)
		if(b&1)s=1LL*s*a%mod;
	return s;
}
void NTT(int*a,int tp){
	ref(i,0,(1<<M)-1)if(r[i]<i)swap(a[i],a[r[i]]);
	for(int i=2;i<=(1<<M);i<<=1){
		int I=i>>1,w=mi(3,(mod-1)/i);
		if(tp<0)w=mi(w,mod-2);
		for(int j=0;j<(1<<M);j+=i)
			for(int k=j,W=1;k<j+I;++k,W=1LL*W*w%mod){
				int A=a[k],B=1LL*a[k+I]*W%mod;
				a[k]=(A+B)%mod;a[k+I]=(mod+A-B)%mod;
			}
	}
	int ni=mi(1<<M,mod-2);
	if(tp<0)ref(i,0,(1<<M)-1)a[i]=1LL*a[i]*ni%mod;
}
int main(){
	cin>>n>>m;
	f[0] = 1;
	ref(i,1,n)f[i] = 1LL*f[i-1]*i%mod;
	F[n] = mi(f[n], mod-2);
	def(i,n,1)F[i-1] = 1LL*F[i]*i%mod;
	ref(i,1,(1<<M)-1)r[i]=(r[i>>1]>>1)|((i&1)<<M-1);
	A[0] = 1;
	ref(i,1,m){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		ref(j,0,n)a[j]=1LL*A[j]*F[j]%mod;
		ref(j,0,n)b[j]=F[j];
		NTT(a,1); NTT(b,1);
		ref(j,0,(1<<M)-1)b[j]=1LL*a[j]*b[j]%mod;
		NTT(b,-1);
		ref(j,0,n)inc(B[j],b[j]);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		ref(j,1,n)a[j]=1LL*A[j]*F[j-1]%mod;
		ref(j,1,n)b[j]=F[j+1]*2%mod; b[0]=F[1];
		NTT(a,1); NTT(b,1);
		ref(j,0,(1<<M)-1)b[j]=1LL*a[j]*b[j]%mod;
		NTT(b,-1);
		ref(j,0,n)inc(B[j],b[j]);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		ref(j,2,n)a[j]=1LL*A[j]*F[j-2]%mod;
		ref(j,0,n)b[j]=F[j+2];
		NTT(a,1); NTT(b,1);
		ref(j,0,(1<<M)-1)b[j]=1LL*a[j]*b[j]%mod;
		NTT(b,-1);
		ref(j,0,n)inc(B[j],b[j]);
		
		ref(j,0,n)A[j]=1LL*B[j]*f[j]%mod,B[j]=0;
	}
	ref(i,0,n)inc(ans,1LL*C(n,i)*A[i]%mod);
	cout<<ans<<endl;
}