#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define db double
#define pint pair<int,int>
#define mk(x,y) make_pair(x,y)
#define fir first
#define sec second
#define Rep(x,y,z) for(int x=y;x<=z;x++)
#define Red(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
const int MAXN=3005;
char buf[1<<12],*pp1=buf,*pp2=buf,nc;int ny;
inline char gc() {return pp1==pp2&&(pp2=(pp1=buf)+fread(buf,1,1<<12,stdin),pp1==pp2)?EOF:*pp1++;}
//inline char gc(){return getchar();}
inline int read(){
	int x=0;for(ny=1;nc=gc(),(nc<48||nc>57)&&nc!=EOF;)if(nc==45)ny=-1;if(nc<0)return nc;
	for(x=nc-48;nc=gc(),47<nc&&nc<58&&nc!=EOF;x=(x<<3)+(x<<1)+(nc^48));return x*ny;
}
inline int Fp(int x,int k,int Mod){int ans=1;for(;k;k>>=1,x=1ll*x*x%Mod)if(k&1)ans=1ll*ans*x%Mod;return ans;}
int n,Mod,C[MAXN][MAXN],S[MAXN][MAXN],Ans;
int main(){
//	freopen("std.in","r",stdin);
//	freopen("std.out","w",stdout);
	n=read(),Mod=read();
	S[0][0]=C[0][0]=1;
	Rep(i,1,n+1){C[i][0]=1;Rep(j,1,i)S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j])%Mod,C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;}
	Rep(i,0,n){
		int tmp=1,o=Fp(2,n-i,Mod),Sum=0;
		Rep(j,0,i)Sum=(Sum+1ll*S[i+1][j+1]*tmp)%Mod,tmp=1ll*tmp*o%Mod;
		if(i&1)Ans=(Ans-1ll*Sum*Fp(2,Fp(2,n-i,Mod-1),Mod)%Mod*C[n][i])%Mod;else Ans=(Ans+1ll*Sum*Fp(2,Fp(2,n-i,Mod-1),Mod)%Mod*C[n][i])%Mod;
	}cout<<(Ans+Mod)%Mod<<"\n";
	return 0;
}


