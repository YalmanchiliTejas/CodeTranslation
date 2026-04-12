#include <bits/stdc++.h>
#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define ROF(i,a,b) for(register int i=(a);i>=(b);--i)
#define pi pair<int,int>
#define mk(a,b) make_pair(a,b)
#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)
#define fi first
#define se second
#define ls(x) t[x].lson
#define rs(x) t[x].rson
#define d(a,b) dp[min(a,b)][max(a,b)]
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 2005;
const int maxm = 1000005;
const int inf = 2147483647;
typedef long long ll;
const double eps = 1e-9;
const long long INF = 9223372036854775807ll;
ll qpow(ll a,ll b,ll c){ll ans=1;while(b){if(b&1)ans=ans*a%c;a=a*a%c;b>>=1;}return ans;}
inline void rd(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
inline void rd(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
inline void rd(db *x){scanf("%lf",x);}
inline int rd(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
inline void rd(int a[],int n){FOR(i,0,n)rd(&a[i]);}
inline void rd(ll a[],int n){FOR(i,0,n)rd(&a[i]);}
template <class T, class S> inline void rd(T *x, S *y){rd(x);rd(y);}
template <class T, class S, class U> inline void rd(T *x, S *y, U *z){rd(x);rd(y);rd(z);}
template <class T, class S, class U, class V> inline void rd(T *x, S *y, U *z, V *w){rd(x);rd(y);rd(z);rd(w);}
inline void wr(int x){if(x < 10) putchar('0' + x); else wr(x / 10), wr(x % 10);}
inline void wr(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
inline void wr(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
inline void wr(db x, char c){printf("%.15f",x);mypc(c);}
inline void wr(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
inline void wr(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> inline void wrn(T x){wr(x,'\n');}
template<class T, class S> inline void wrn(T x, S y){wr(x,' ');wr(y,'\n');}
template<class T, class S, class U> inline void wrn(T x, S y, U z){wr(x,' ');wr(y,' ');wr(z,'\n');}
template<class T, class S, class U,class H> inline void wrn(T x, S y, U z,H h){wr(x,' ');wr(y,' ');wr(z,' ');wr(h,'\n');}
template<class T> inline void wra(T x[], int n){int i;if(!n){mypc('\n');return;}FOR(i,0,n-1)wr(x[i],' ');wr(x[n-1],'\n');}
int b[maxn*3],a[maxn*3],tot,dp[maxn][maxn],mx[maxn],mxas;
struct Node{
	int u,v,w;
};
vector<Node>g;
void up(int u,int v,int w){
//	wrn(min(u,v),max(u,v),w);
	d(u,v)=max(d(u,v),w);
	mxas=max(mxas,w);
	mx[u]=max(mx[u],w);
	mx[v]=max(mx[v],w);
}
void rec(int u,int v,int w){
	g.push_back(Node{u,v,w});
}
int main(){
	int n,ans=0;
	rd(&n);rd(b+1,3*n);
	if(n==1)return wrn(b[1]==b[2] && b[2]==b[3]),0;
	sort(b+1,b+6);
	bool fg=1;
	FOR(i,1,4){
		if(b[i]==b[i+1] && b[i+1]==b[i+2]){
			ans++;
			FOR(j,1,i)a[++tot]=b[j];
			FOR(j,i+3,6)a[++tot]=b[j];
			fg=0;
			break;
		}
	}
	if(fg)FOR(i,1,6)a[++tot]=b[i];
	for(int i=6;i<3*n;i+=3){
		if(b[i]==b[i+1] && b[i+1]==b[i+2]){
			ans++;
		}else{
			a[++tot]=b[i],a[++tot]=b[i+1],a[++tot]=b[i+2];
		}
	} 
	a[++tot]=b[3*n];
	FOR(i,1,n+1)FOR(j,i,n+1)dp[i][j]=-inf/2,mx[i]=-inf/2,mxas=-inf/2;
	up(a[1],a[2],0);
	FOR(i,3,tot){
		g.clear();
		if(a[i]==a[i+1])swap(a[i],a[i+2]);
		else if(a[i]==a[i+2])swap(a[i],a[i+1]);
		if(a[i+1]==a[i+2]){
			FOR(j,1,n+1)rec(j,a[i],d(j,a[i+1])+1);
		}
		rec(a[i],a[i+1],mxas),rec(a[i],a[i+2],mxas),rec(a[i+1],a[i+2],mxas);
		rec(a[i],a[i+1],d(a[i+2],a[i+2])+1),rec(a[i],a[i+2],d(a[i+1],a[i+1])+1),rec(a[i+1],a[i+2],d(a[i],a[i])+1);
		FOR(j,1,n+1)rec(j,a[i],mx[j]),rec(j,a[i+1],mx[j]),rec(j,a[i+2],mx[j]);
		FOR(j,0,g.size())up(g[j].u,g[j].v,g[j].w);
//		wrn("ggggggggggggggggggggggggggggggggg");
//		FOR(j,1,n+1)
//		FOR(k,j,n+1)wrn(j,k,d(j,k));
//		wrn("fffffffffffffffffffffffffffffffff");
		i+=2;
	}
	int as=0;
	as=max(mxas,d(a[tot],a[tot])+1);
	ans+=as;
	wrn(ans);
} 