#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=105,mod=1e9+7,INF=mod+233;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
int n;
int a[N];
int g[N][N],f[N][N];
void dfs(int L,int R,int h){
	if (L==R){
		g[L][R]=Pow(2,a[L]-h);
		f[L][R]=0;
//		printf("dfs(%d,%d,%d): ",L,R,h);
//		printf("g = %d, f = %d\n",g[L][R],f[L][R]);
		return;
	}
	int mi=INF;
	For(i,L,R)
		mi=min(mi,a[i]);
	int las=L;
	For(i,L,R){
		if (a[i]==mi){
			if (las<i){
				dfs(las,i-1,mi);
				if (las==L){
					g[L][R]=g[las][i-1];
					f[L][R]=f[las][i-1];
					las=i;
				}
				else {
					int g0=g[L][R],g1=g[las][i-1];
					int f0=f[L][R],f1=f[las][i-1];
					g[L][R]=(LL)g0*g1%mod;
					f[L][R]=0;
					Add(f[L][R],(LL)g0*g1%mod);
					Add(f[L][R],(LL)f0*g1*2%mod);
					Add(f[L][R],(LL)g0*f1*2%mod);
					Add(f[L][R],(LL)f0*f1*2%mod);
				}
			}
			dfs(i,i,mi);
			if (las==L){
				g[L][R]=g[i][i];
				f[L][R]=f[i][i];
			}
			else {
				int g0=g[L][R],g1=g[i][i];
				int f0=f[L][R],f1=f[i][i];
				g[L][R]=(LL)g0*g1%mod;
				f[L][R]=0;
				Add(f[L][R],(LL)g0*g1%mod);
				Add(f[L][R],(LL)f0*g1*2%mod);
				Add(f[L][R],(LL)g0*f1*2%mod);
				Add(f[L][R],(LL)f0*f1*2%mod);
			}
			las=i+1;
		}
	}
	if (las<=R){
		dfs(las,R,mi);
		int g0=g[L][R],g1=g[las][R];
		int f0=f[L][R],f1=f[las][R];
		g[L][R]=(LL)g0*g1%mod;
		f[L][R]=0;
		Add(f[L][R],(LL)g0*g1%mod);
		Add(f[L][R],(LL)f0*g1*2%mod);
		Add(f[L][R],(LL)g0*f1*2%mod);
		Add(f[L][R],(LL)f0*f1*2%mod);
	}
	g[L][R]=(LL)g[L][R]*Pow(2,mi-h)%mod;
//	printf("dfs(%d,%d,%d): ",L,R,h);
//	printf("g = %d, f = %d\n",g[L][R],f[L][R]);
}
int main(){
	n=read();
	For(i,1,n)
		a[i]=read();
	dfs(1,n,1);
	int ans=Add(g[1][n]+f[1][n]);
	Add(ans,ans);
	cout<<ans<<endl;
	return 0;
}