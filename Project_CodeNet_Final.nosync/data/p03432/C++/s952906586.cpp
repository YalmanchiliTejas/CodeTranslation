#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pint pair<int,int>
#define mk(x,y) make_pair(x,y)
#define fir first
#define sec second
#define Rep(x,y,z) for(int x=y;x<=z;++x)
#define Red(x,y,z) for(int x=y;x>=z;--x)
using namespace std;
const int MAXN=5e4+5,Mod=998244353,G=3;
char buf[1<<12],*p1=buf,*p2=buf,nc;int ny;
inline char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
//inline char gc(){return getchar();}
inline int read(){
	int x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;if(nc<0)return nc;
	x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48);return x*ny;
}int n,m,l,r[MAXN],wi[MAXN],Fac[MAXN],iFac[MAXN],inv[MAXN];
inline int C(int n,int m){if(n<0||m<0||n<m)return 0;return 1ll*Fac[n]*iFac[m]%Mod*iFac[n-m]%Mod;}
inline int Fp(int x,int k){int ans=1;for(;k;k>>=1,x=1ll*x*x%Mod)if(k&1)ans=1ll*ans*x%Mod;return ans;}
inline int Trans(int n){
	int N,c;
	for(N=1,c=0;N<n;N<<=1,c++);
	for(int i=0;i<N;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(c-1));
	return N;
}inline void NTT(int*F,int len,int opt){
	for(int i=0;i<len;i++)if(i<r[i])swap(F[i],F[r[i]]);
	for(int i=1;i<len;i<<=1){
		int w=Fp(G,(Mod-1)+opt*(Mod-1)/(i<<1));wi[0]=1;
		Rep(j,1,i)wi[j]=1ll*wi[j-1]*w%Mod;
		for(int j=0;j<len;j+=i<<1){
			for(int k=0;k<i;k++){
				int x=1ll*F[i+j+k]*wi[k]%Mod,y=F[j+k];
				F[i+j+k]=(y-x+Mod)%Mod,F[j+k]=(x+y)%Mod;
			}
		}
	}if(opt==-1){int Inv=Fp(len,Mod-2);for(int i=0;i<len;i++)F[i]=1ll*F[i]*Inv%Mod;}
}int F[205][8005],A[MAXN],B[MAXN];
int main(){
//	freopen("std.in","r",stdin);
//	freopen("std.out","w",stdout);
	inv[1]=1;Rep(i,2,MAXN-1)inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	Fac[0]=iFac[0]=1;Rep(i,1,MAXN-1)Fac[i]=1ll*Fac[i-1]*i%Mod,iFac[i]=1ll*inv[i]*iFac[i-1]%Mod;
	n=read(),m=read(),l=Trans(2*(n+2));
	Rep(i,0,n)F[m][i]=C(n,i);
	Rep(i,0,n)A[i]=10;NTT(A,l,1),NTT(A,l,-1);
	Red(i,m-1,0){
		Rep(j,0,n)F[i][j]=(F[i][j]+1ll*F[i+1][j]*(C(j+1,2)+1))%Mod;
		memset(A,0,sizeof(A)),memset(B,0,sizeof(B));
		Rep(j,0,n)B[j+2]=1ll*F[i+1][j]*Fac[j+2]%Mod;
		Rep(j,3,n+2)A[j]=iFac[j];reverse(A,A+n+3);
		NTT(A,l,1),NTT(B,l,1);Rep(j,0,l)A[j]=1ll*A[j]*B[j]%Mod;NTT(A,l,-1);
		Rep(j,0,n)F[i][j]=(F[i][j]+1ll*A[j+n+2]*iFac[j])%Mod;
	}cout<<F[0][0]<<"\n";
	return 0;
}

