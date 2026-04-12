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
const int MAXN=2e5+5,Mod=1e9+7;
char buf[1<<12],*pp1=buf,*pp2=buf,nc;int ny;
//inline char gc() {return pp1==pp2&&(pp2=(pp1=buf)+fread(buf,1,1<<12,stdin),pp1==pp2)?EOF:*pp1++;}
inline char gc(){return getchar();}
inline int read(){
	int x=0;for(ny=1;nc=gc(),(nc<48||nc>57)&&nc!=EOF;)if(nc==45)ny=-1;if(nc<0)return nc;
	for(x=nc-48;nc=gc(),47<nc&&nc<58&&nc!=EOF;x=(x<<3)+(x<<1)+(nc^48));return x*ny;
}int n,m,Mx,p,ans,F[MAXN],Sum[MAXN];char s[MAXN];
int main(){
//	freopen("std.in","r",stdin);
//	freopen("std.out","w",stdout);
	n=read(),m=read(),scanf("%s",s+1),Mx=m,p=m+1;
	Rep(i,1,m)if(s[i]!=s[1]){Mx=i-1,p=i;break;}
	if(Mx==m){
		F[0]=Sum[0]=ans=1;
		Rep(i,0,n)(i>=2?F[i]=Sum[i-2]:0),(i?Sum[i]=(Sum[i-1]+F[i])%Mod:0),(n-i>=2?ans=(ans+1ll*F[i]*(n-i))%Mod:0);
		cout<<ans<<'\n';return 0;
	}if(n&1)return puts("0"),0;if(!(Mx&1))Mx++;
	for(int t=0,i=p;i<=m;i++)if(s[i]==s[1])t++;else (t&1?Mx=min(Mx,t):0),t=0;
	n/=2,Mx=(Mx+1)/2,F[0]=Sum[0]=1;
	Rep(i,0,n){
		if(i)F[i]=(Sum[i-1]-(i-Mx-1>=0?Sum[i-Mx-1]:0)+Mod)%Mod,Sum[i]=(Sum[i-1]+F[i])%Mod;
		if(n-i<=Mx)ans=(ans+1ll*F[i]*(n-i)*2)%Mod;
	}cout<<ans<<'\n';
	return 0;
}


