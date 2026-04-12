#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 1002, M = 500000;


inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int n,m,d[N][N],sz,dy[N][N],s,t,C[N][N];
bool ok[N][N];
int tot,st1[M],st2[M],st3[M],a[N],b[N];
bool mrk[M];
int main() { //freopen("1.in","r",stdin);
	read(n); read(m); rep(i,1,n) rep(j,1,m) read(d[i][j]);
	s=203; t=s+1;
	if (n==1&&m==1) {
		puts("Possible");
		printf("2 1\n");
		printf("1 2 %d\n",d[1][1]);
		printf("1 2");
		return 0;
	}
	
	
	rep(A,0,100) rep(B,0,100) {
		int mx=0;
		rep(i,1,n) rep(j,1,m) mx=max(mx,d[i][j]-A*i-B*j);
		rep(i,1,n) rep(j,1,m) if (d[i][j]-A*i-B*j==mx) ok[i][j]=1;
		C[A][B]=mx;
	}
	rep(i,1,n) rep(j,1,m) if (!ok[i][j]) {puts("Impossible"); return 0;}
	
	
	rep(i,0,100) a[i]=++sz;
	rep(i,0,100) b[i]=++sz;
	st1[++tot]=s; st2[tot]=a[0]; st3[tot]=0;
	st1[++tot]=b[0]; st2[tot]=t; st3[tot]=0;
	rep(i,0,99) {st1[++tot]=a[i]; st2[tot]=a[i+1]; st3[tot]=1; mrk[tot]=1;}
	rep(i,0,99) {st1[++tot]=b[i+1]; st2[tot]=b[i]; st3[tot]=2; mrk[tot]=1;}	
	rep(i,0,100) rep(j,0,100) {st1[++tot]=a[i]; st2[tot]=b[j]; st3[tot]=C[i][j];}
	
	
	puts("Possible");
	printf("%d %d\n",t,tot);
	rep(i,1,tot) {
		printf("%d %d ",st1[i],st2[i]);
		if (!mrk[i]) printf("%d",st3[i]); else printf("%c",st3[i]==1?'X':'Y');
		puts("");
	}
	printf("%d %d",s,t);
	return 0;
}