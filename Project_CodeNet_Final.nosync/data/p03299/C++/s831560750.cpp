#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define LL long long
#define fgx cerr<<"--------------"<<endl;
#define dgx cerr<<"=============="<<endl;

inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int MAXN = 10010;
const int INF = 2147483600;
const LL Mod = 1000000007LL;

int N; int a[MAXN+1]; 

int f[19][MAXN+1],g[19][MAXN+1],Log2[MAXN+1],mn;
inline LL Pow(LL a,LL b){
	LL ret=1; for(;b;b>>=1,a=a*a%Mod) if(b&1) ret=ret*a%Mod; return ret;
}
inline int qry(int l,int r){
	int x=Log2[r-l+1]; mn=min(f[x][l],f[x][r-(1<<x)+1]);
	if(f[x][l]<=f[x][r-(1<<x)+1]) return g[x][l];
	else return g[x][r-(1<<x)+1];
}
inline void Init(){
	for(int i=1;i<N;i++) f[0][i]=a[i],g[0][i]=i;
	for(int i=2;i<N;i++) Log2[i]=Log2[i>>1]+1;
	for(int j=1;j<=15;j++){
		for(int i=1;i+(1<<j)-1<N;i++){
			f[j][i]=min(f[j-1][i],f[j-1][i+(1<<(j-1))]); g[j][i]=INF;
			if(f[j-1][i]==f[j][i]) g[j][i]=min(g[j][i],g[j-1][i]);
			if(f[j-1][i+(1<<(j-1))]==f[j][i]) g[j][i]=min(g[j][i],g[j-1][i+(1<<(j-1))]); 
		}
	}
} int cnt; LL Len[MAXN+1],ln[MAXN+1],rn[MAXN+1],To[MAXN+1]; LL Sum[MAXN+1];
int nxt[MAXN+1];
inline int div(int base,int l,int r){
	int x=qry(l,r); int bs=mn,id=cnt+1,nx; ln[++cnt]=l; rn[cnt]=r; Sum[cnt]=bs-base; Len[cnt]=Sum[cnt];
	int last=l-1; while(x<=r&&x){ if(last+1<x) {nx=div(bs,last+1,x-1); Sum[id]+=Sum[nx];} last=x; x=nxt[x]; } 
	if(last<r) nx=div(bs,last+1,r),Sum[id]+=Sum[nx];
	To[id]=cnt+1;
	return id;
}
int b[MAXN+1],pos[MAXN+1]; LL h[MAXN+1]; LL Pw2[MAXN+1];

int main(){
	//freopen("a.in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(); LL anspw=0;
	for(int i=1;i<=N;i++) a[i]=read();
	if(N==1){
		printf("%lld\n",Pow(2,a[1])); return 0;
	}
	for(int i=1;i<=N;i++){
		if(a[i]>a[i-1]&&a[i]>a[i+1]){
			int d=a[i];
			a[i]=max(a[i-1],a[i+1]); anspw+=d-a[i];
		}
	} for(int i=1;i<=N;i++) a[i]--;
	for(int i=1;i<N;i++) a[i]=min(a[i],a[i+1]),b[i]=a[i];
	sort(b+1,b+N); int n=unique(b+1,b+N)-b-1;
	for(int i=1;i<N;i++){
		int c=lower_bound(b+1,b+n+1,a[i])-b;
		nxt[pos[c]]=i; pos[c]=i;
	} Init(); div(0,1,N-1);
	h[1]=1; Pw2[0]=1;
	for(int i=1;i<=N;i++) Pw2[i]=Pw2[i-1]*2%Mod;
	ln[cnt+1]=rn[cnt+1]=N;
	for(int i=1;i<=cnt;i++){
		if(!To[i]) To[i]=cnt+1;
		(h[To[i]]+=h[i]*((Pow(2,Sum[i])-Pow(2,Sum[i]-Len[i])+Mod)%Mod)%Mod*Pw2[ln[To[i]]-rn[i]-1]%Mod)%=Mod;
		(h[i+1]+=h[i]*((Pw2[ln[i+1]-ln[i]]+Mod)%Mod)%Mod)%=Mod;
	} 	printf("%lld\n",h[cnt+1]*Pow(2,anspw)%Mod*2%Mod);
	return 0;
}