#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=100100,M=400400,P=1000000007;
int i,j,k,n,m,ch,ff,S,T,Hn,dn,ans,En;
int h[N],d[N],z[N],f[N],g[N];
ll dis[N];
struct edge { int s,n,v;} E[M];
struct cc {
	int x;
	ll y;
	bool operator < (const cc &n) const {
		return y<n.y;
	}
} H[N+M];
void R(int &x) {
	ff=x=0;ch=getchar();
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x=-x;
}
void W(int x) {
	if (x<0) putchar('-'),x=-x;
	if (x>=10) W(x/10);
	putchar(x%10+'0');
}
void up(int x) {
	while (x>1 && H[x]<H[x>>1]) swap(H[x],H[x>>1]),x>>=1;
}
void down(int x) {
	while ((x<<1)<=Hn) {
		int k=x<<1;
		if (k<Hn && H[k|1]<H[k]) k|=1;
		if (H[k]<H[x]) swap(H[x],H[k]),x=k;
		else break;
	}
}
int C2(int x) {
	return (ll) x*x%P;
}
void E_add(int x,int y,int v) {
	E[++En].s=y;E[En].v=v;
	E[En].n=h[x];h[x]=En;
	E[++En].s=x;E[En].v=v;
	E[En].n=h[y];h[y]=En;
}
int main() {
	R(n);R(m);
	R(S);R(T);
	for (i=1;i<=m;i++) {
		int x,y,v;
		R(x);R(y);R(v);
		E_add(x,y,v);
	}
	memset(dis,1,sizeof dis);
	dis[S]=0;
	z[S]=1;
	cc t;
	t.x=S;t.y=0;
	H[++Hn]=t;
	up(Hn);
	while (Hn) {
		cc tt=H[1];
		d[++dn]=tt.x;
		z[tt.x]=1;
		H[1]=H[Hn--];
		down(1);
		for (k=h[tt.x];k;k=E[k].n) if (!z[E[k].s] && tt.y+E[k].v<dis[E[k].s]) {
			dis[E[k].s]=tt.y+E[k].v;
			t.x=E[k].s;
			t.y=dis[E[k].s];
			H[++Hn]=t;
			up(Hn);
		}
		while (Hn && z[H[1].x]) {
			H[1]=H[Hn--];
			down(1);
		}
	}
	f[S]=1;g[T]=1;
	for (i=1;i<=dn;i++) if (f[d[i]])
		for (k=h[d[i]];k;k=E[k].n) if (dis[d[i]]+E[k].v==dis[E[k].s]) f[E[k].s]=(f[E[k].s]+f[d[i]])%P;
	for (i=dn;i;i--)
		for (k=h[d[i]];k;k=E[k].n) if (dis[d[i]]+E[k].v==dis[E[k].s]) g[d[i]]=(g[E[k].s]+g[d[i]])%P;
	ans=C2(f[T]);
	for (i=1;i<=dn;i++) {
		int num=0;
		for (k=h[d[i]];k;k=E[k].n) {
			if (dis[d[i]]+E[k].v==dis[E[k].s] && 2ll*dis[d[i]]<dis[T] && dis[T]<2ll*dis[E[k].s]) ans=(ans+P-C2((ll) f[d[i]]*g[E[k].s]%P))%P;
			if (dis[d[i]]+E[k].v==dis[E[k].s] && 2ll*dis[d[i]]==dis[T]) num=((ll) f[d[i]]*g[E[k].s]+num)%P;
		}
		ans=(ans+P-C2(num))%P;
	}
	printf("%d\n",ans);
}