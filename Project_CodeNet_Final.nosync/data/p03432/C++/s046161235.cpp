#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=8005,M=205,P=998244353;
int n,m,f[N][M],fac[N],ifac[N],inv[N];
int fpow(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=1LL*k1*k1%P)if(k2&1)k3=1LL*k3*k1%P;
	return k3;
}
void addx(int&k1,int k2){
	(k1+=k2)>=P&&(k1-=P);
}
int add(int k1,int k2){
	addx(k1,k2);
	return k1;
}
void subx(int&k1,int k2){
	(k1-=k2)<0&&(k1+=P);
}
int sub(int k1,int k2){
	subx(k1,k2);
	return k1;
}
void ntt(vector<int>&a,int g,int lim){
	a.resize(lim);
	for(int i=0,j=0;i<lim;++i){
		if(i<j)swap(a[i],a[j]);
		for(int k=(lim>>1);(j^=k)<k;k>>=1);
	}
	vector<int>w(lim>>1);
	w[0]=1;
	for(int i=1;i<lim;i<<=1){
		for(int j=1,wn=fpow(g,(P-1)/(i<<1));j<i;++j)w[j]=1LL*w[j-1]*wn%P;
		for(int j=0;j<lim;j+=i<<1)for(int k=0;k<i;++k){
			int x=a[j+k],y=1LL*a[i+j+k]*w[k]%P;
			a[j+k]=add(x,y),a[i+j+k]=sub(x,y);
		}
	}
	if(g!=3){
		int I=fpow(lim,P-2);
		for(int i=0;i<lim;++i){
			a[i]=1LL*a[i]*I%P;
		}
	}
}
int getlim(int k1){
	int k2=1;
	while(k2<=k1)k2<<=1;
	return k2;
}
vector<int>pmul(vector<int>a,vector<int>b){
	int need=SZ(a)+SZ(b)-1;
	int lim=getlim(need);
	ntt(a,3,lim),ntt(b,3,lim);
	rep(i,0,lim-1)a[i]=1LL*a[i]*b[i]%P;
	ntt(a,332748118,lim);
	return a.resize(need),a;
}
void pt(vector<int>a){
	for(int i=0;i<SZ(a);++i)D(" %d"+(i==0),a[i]);
	D("\n");
}
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*ifac[k2]%P*ifac[k1-k2]%P;
}
int main(){
	fac[0]=fac[1]=ifac[0]=ifac[1]=inv[0]=inv[1]=1;
	rep(i,2,N-1)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	scanf("%d%d",&n,&m);
	f[0][0]=1;
	rep(j,1,m){
		vector<int>F(n+1);
		rep(i,0,n){
			F[i]=1LL*f[i][j-1]*ifac[i]%P;
		}
		vector<int>G(ifac,ifac+3+n);
		G[0]=G[1]=G[2]=0;
		F=pmul(F,G);
		//D("F[%d]=",j);
		//pt(F);
		rep(i,0,n){
			f[i][j]=1LL*fac[i+2]*F[i+2]%P;
		}
		rep(i,0,n){
			addx(f[i][j],1LL*f[i][j-1]*(1LL*i*(i+1)/2%P+1)%P);
		}
	}
	int ans=0;
	for(int i=0;i<=n;++i){
		addx(ans,1LL*C(n,i)*f[i][m]%P);
	}
	printf("%d\n",ans);
	return 0;
}