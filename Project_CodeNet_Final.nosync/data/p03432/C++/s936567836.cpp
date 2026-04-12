#include<bits/stdc++.h>
using namespace std;
template<typename T>inline T read(){
	T f=0,x=0;char c=getchar();
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-48,c=getchar();
	return f?-x:x;
}
namespace run{
	const int N=4e4+9,mod=998244353;
	inline int add(int x,int y){return x+y>=mod?x-mod+y:x+y;}
	inline int sub(int x,int y){return x>=y?x-y:x+mod-y;}
	inline int qpow(int x,int y){
		int ret=1;
		while(y){
			if(y&1) ret=1LL*x*ret%mod;
			x=1LL*x*x%mod,y>>=1;
		}
		return ret;
	}

	int rev[N],limit,bit,Gi=qpow(3,mod-2);
	inline void prepare(int len){
		limit=1,bit=0;
		while(limit<len) limit<<=1,bit++;
		for(int i=1;i<limit;i++)
			rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	}
	inline void NTT(int *a,int inv){
		for(int i=1;i<limit;i++)
			if(i<rev[i]) swap(a[i],a[rev[i]]);
		for(int mid=1;mid<limit;mid<<=1){
			int tmp=qpow(~inv?3:Gi,(mod-1)/(mid<<1));
			for(int i=0,R=mid<<1;i<limit;i+=R)
				for(int j=0,omega=1;j<mid;j++,omega=1LL*omega*tmp%mod){
					int x=a[i+j],y=1LL*omega*a[i+j+mid]%mod;
					a[i+j]=add(x,y),a[i+j+mid]=sub(x,y);
				}
		}
		if(inv==-1){
			inv=qpow(limit,mod-2);
			for(int i=0;i<limit;i++) a[i]=1LL*a[i]*inv%mod;
		}
	}

	int n,m,fac[N],ifac[N],f[201][8009];
	inline int C(int _n,int _m){
		if(_n<0 || _m<0 || _n<_m) return 0;
		return 1LL*fac[_n]*ifac[_m]%mod*ifac[_n-_m]%mod;
	}
	int A[N],B[N];
	inline void dp(){
		for(int i=1;i<=n;i++) B[i]=ifac[i+2];
		prepare(n+n+1),NTT(B,1),f[0][0]=1;
		for(int j=1;j<=m;j++){
			for(int i=0;i<=n;i++) A[i]=1LL*f[j-1][i]*ifac[i]%mod;
			for(int i=n+1;i<limit;i++) A[i]=0;
			NTT(A,1);
			for(int i=0;i<limit;i++) A[i]=1LL*A[i]*B[i]%mod;
			NTT(A,-1);
			for(int i=1;i<=n;i++) f[j][i]=1LL*A[i]*fac[i+2]%mod;
			for(int i=1;i<=n;i++) f[j][i]=(1LL*(1+i+C(i,2))*f[j-1][i]+f[j][i])%mod;
			f[j][0]=1;

		//	for(int i=1;i<=n;i++) cout<<f[j][i]<<" ";
		//	cout<<endl;
		}
	}

	int main(){
		n=read<int>(),m=read<int>();
		fac[0]=ifac[0]=1;
		for(int i=1;i<=n+3;i++) fac[i]=1LL*fac[i-1]*i%mod;
		ifac[n+3]=qpow(fac[n+3],mod-2);
		for(int i=n+2;i>=1;i--) ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
		dp();

		int ans=0;
		for(int i=0;i<=n;i++) ans=(1LL*C(n,i)*f[m][i]+ans)%mod;
		printf("%d\n",ans);
		return 0;
	}
}
int main(){
#ifdef my
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	return run::main();
}