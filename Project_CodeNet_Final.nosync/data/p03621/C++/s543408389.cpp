#include<bits/stdc++.h>
using namespace std;
typedef vector<int>VI;
const int N=4e4,mo=998244353;
inline int poww(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
struct NTT{
	int b[N],wn[N],l,invl;
	inline void ini(int n){
		invl=poww(l=n,mo-2);int i;
		for(i=1;i<l;++i)b[i]=b[i>>1]>>1|(i&1?l>>1:0);
		for(i=2,wn[*wn=1]=poww(3,(mo-1)/l);i<=l;++i)wn[i]=1ll*wn[i-1]*wn[1]%mo;
	}
	inline void DFT(int*a,int key){
		static int c[N],w[N];int i,j,k,m,u;
		memcpy(c,a,l<<2);for(i=0;i<l;++i)a[b[i]]=c[i];
		for(i=2;i<=l;i<<=1){
			for(j=k=0,m=i>>1;k<m;j+=l/i,++k)w[k]=wn[j];
			for(j=0;j<l;j+=i)for(k=0;k<m;++k)u=1ll*a[j+k+m]*w[k]%mo,
				a[j+k+m]=a[j+k]-u,a[j+k+m]+=a[j+k+m]>>31&mo,a[j+k]+=u-mo,a[j+k]+=a[j+k]>>31&mo;
		}		
		if(key==-1)for(reverse(a+1,a+l),i=0;i<l;++i)a[i]=1ll*a[i]*invl%mo;
	}
}F[20];
int lo[N];
inline void getinv(int*A,int n){
	static int B[N],C[N];int i,j;
	memset(B,0,8<<n);*B=poww(*A,mo-2);
	for(i=1;i<=n;++i){
		memcpy(C,A,4<<i);F[i+1].DFT(B,1);F[i+1].DFT(C,1);
		for(j=0;j<F[i+1].l;++j)B[j]=(2ll*B[j]+mo-1ll*C[j]*B[j]%mo*B[j]%mo)%mo;F[i+1].DFT(B,-1);
		memset(B+(1<<i),0,4<<i);memset(C,0,8<<i);
	}
	memcpy(A,B,4<<n);
}
inline void mul(const int*a,const int*b,int*c,int n,int m){
	static int A[N],B[N];int i,l=lo[n+m-1];
	memset(A,0,4<<l);memset(B,0,4<<l);memcpy(A,a,n<<2);memcpy(B,b,m<<2);
	F[l].DFT(A,1);F[l].DFT(B,1);for(i=0;i<1<<l;++i)A[i]=1ll*A[i]*B[i]%mo;
	F[l].DFT(A,-1);memcpy(c,A,n+m-1<<2);
}
int fac[N],i,a,b;
char c1[N],c2[N];
inline VI mul(const VI&a,const VI&b){
	static VI c;c.resize(a.size()+b.size()-1);
	mul(&a[0],&b[0],&c[0],a.size(),b.size());c.resize(::a+1);return c;
}
int main(){
	for(i=0;i<16;++i)F[i].ini(1<<i);for(i=2;i<N;++i)lo[i]=lo[i-1]+!((i-2)&(i-1));
	for(i=*fac=1;i<N;++i)fac[i]=1ll*fac[i-1]*i%mo;
	scanf("%s%s",c1+1,c2+1);
	for(i=1;c1[i];++i)a+=c1[i]=='1' && c2[i]=='1',b+=c1[i]!=c2[i];b/=2;
	VI A,B;A.resize(a+1);B={1};for(i=0;i<=a;++i)A[i]=poww(fac[i+1],mo-2);
	for(i=b;i;i>>=1,A=mul(A,A))if(i&1)B=mul(B,A);
	i=0;for(int x:B)i=(i+x)%mo;i=1ll*fac[a]*fac[b]%mo*fac[a+b]%mo*i%mo;
	printf("%d\n",i);
	return 0;
}