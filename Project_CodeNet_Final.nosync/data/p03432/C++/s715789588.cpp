#include<bits/stdc++.h>
using namespace std;
const int N=17005,mo=998244353;
int poww(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
struct NTT{
	int b[N],l,invl,wn[N];
	inline void ini(int n){
		for(l=1;l<=n;l<<=1);
		int i,j,k,m;static int c[N];
		for(i=0;i<l;++i)b[i]=i;
		for(i=l;i>1;i>>=1)
			for(j=0,m=i>>1,memcpy(c,b,l<<2);j<l;j+=i)
				for(k=0;k<m;++k)b[j+k]=c[j+(k<<1)],b[j+k+m]=c[j+(k<<1|1)];
		wn[0]=1;wn[1]=poww(3,(mo-1)/l);
		for(i=2;i<=l;++i)wn[i]=1ll*wn[i-1]*wn[1]%mo;
		invl=poww(l,mo-2);
	}
	inline void DFT(int*a,int key){
		static int c[N],w[N];memcpy(c,a,l<<2);
		int i,j,k,m;
		for(i=0;i<l;++i)a[b[i]]=c[i];
		for(i=2;i<=l;i<<=1){
			m=i>>1;
			if(key==1)for(j=0,k=0;j<m;++j,k+=l/i)w[j]=wn[k];
				else for(j=0,k=l;j<m;++j,k-=l/i)w[j]=wn[k];
			for(j=0;j<l;j+=i)
				for(k=0;k<m;++k){
					int u=1ll*w[k]*a[j+k+m]%mo;
					a[j+k+m]=(a[j+k]+mo-u)%mo;
					a[j+k]=(a[j+k]+u)%mo;
				}
		}
		if(key==-1)for(i=0;i<l;++i)a[i]=1ll*a[i]*invl%mo;
	}
}F;
int vf[N],fac[N],inv[N];
inline int C(int n,int m){return n>=m?1ll*vf[m]*vf[n-m]%mo*fac[n]%mo:0;}
int n,m,i,j,k,l,f[205][N],A[N];
int main(){
	for(int i=*vf=*fac=1;i<N;++i)
		inv[i]=i==1?1:1ll*(mo-mo/i)*inv[mo%i]%mo,
		vf[i]=1ll*vf[i-1]*inv[i]%mo,fac[i]=1ll*fac[i-1]*i%mo;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;++i)f[m][i]=C(n,i);
	F.ini(n*2);
	for(i=0;i<=n;++i)A[i]=vf[i+2];F.DFT(A,1);
	for(i=m;i;--i){
		for(j=0;j<=n;++j)f[i-1][j]=mo-1ll*j*f[i][j]%mo,f[i][j]=1ll*fac[j+2]*f[i][j]%mo;
		reverse(f[i],f[i]+n+1);F.DFT(f[i],1);for(j=0;j<F.l;++j)f[i][j]=1ll*f[i][j]*A[j]%mo;F.DFT(f[i],-1);
		for(j=0;j<=n;++j)f[i-1][j]=(f[i-1][j]+1ll*vf[j]*f[i][n-j])%mo;
	}
	printf("%d\n",f[0][0]);
	return 0;
}