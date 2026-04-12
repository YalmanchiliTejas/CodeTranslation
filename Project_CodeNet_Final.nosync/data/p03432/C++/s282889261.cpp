#include<bits/stdc++.h>
#define ll long long
#define re register
#define Node vector<int>
#define ull unsigned long long
using namespace std;
inline int read(){
	int s=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return s*t;
}
const int N=3e5+5;
const int M=205;
const int P=998244353;
int n,m,fac[N],inv[N];
int Mod(int x){return x>=P?x-P:x;}
int ksm(int x,int k){
	int res=1;
	while(k){
		if(k&1)res=1ll*res*x%P;
		x=1ll*x*x%P,k>>=1;
	}return res;
}
namespace Number{
	const int G=3;
	int Lim,p[N],w[N];
	void Init(int n){//x^n 
		for(Lim=0;(1<<Lim)<=n;Lim++);
		for(int i=0;i<(1<<Lim);i++)p[i]=(p[i>>1]>>1)|((i&1)<<Lim-1);
		Lim=(1<<Lim);
	}
	void NTT(Node &A,int n,int type){
		w[0]=1;for(int i=0;i<n;i++)if(i<p[i])swap(A[i],A[p[i]]);
		for(int m=1;m<n;m<<=1){
			int t0=ksm(G,P-1+type*(P-1)/(m<<1));
			for(int i=1;i<m;i++)w[i]=1ll*w[i-1]*t0%P;
			for(int k=0;k<n;k+=(m<<1))
			for(int i=k;i<k+m;i++){
				int x=A[i],y=1ll*A[i+m]*w[i-k]%P;
				A[i]=Mod(x+y),A[i+m]=Mod(x+P-y);
			}
		}
		int t0=ksm(n,P-2);
		if(type==-1)for(int i=0;i<n;i++)A[i]=1ll*A[i]*t0%P;
	}
	Node operator*(Node A,Node B){
		int n=A.size()-1,m=B.size()-1;
		Init(n+m+1),A.resize(Lim),B.resize(Lim);
		NTT(A,Lim,1),NTT(B,Lim,1);
		for(int i=0;i<Lim;i++)A[i]=1ll*A[i]*B[i]%P;
		NTT(A,Lim,-1);for(int i=n+m+1;i<Lim;i++)A[i]=0;
		A.resize(n+m+1);return A;
	}
}using namespace Number;
Node f[M],g,h;
int C(int n,int m){return 1ll*fac[n]*inv[m]%P*inv[n-m]%P;}
void Pre(int n){
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%P;
	inv[n]=ksm(fac[n],P-2);for(int i=n;i>=1;i--)inv[i-1]=1ll*inv[i]*i%P;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(),m=read(),Pre(1e5);
	f[m].resize(n+1);for(int i=0;i<=n;i++)f[m][i]=C(n,i);
	for(int i=m-1;i>=0;i--){
		g.resize(n+1);for(int j=0;j<n;j++)g[j]=inv[n-j+2];
		h.resize(n+1);for(int j=0;j<=n;j++)h[j]=1ll*f[i+1][j]*fac[j+2]%P;
		h=h*g,f[i].resize(n+1);
		for(int j=0;j<=n;j++)f[i][j]=Mod(1ll*h[n+j]*inv[j]%P+1ll*f[i+1][j]*(C(j+1,2)+1)%P);
	}printf("%d",f[0][0]);
	return 0;
}