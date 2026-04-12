#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=200200,oo=1000000001;
int i,j,k,n,m,ch,t,ma,tma,mi,tmi,Rmax,Rmin,Bmax,Bmin,sma,smi;
ll ans;
struct cc {
	int x,y;
	bool operator < (const cc &n) const {
		if (x==n.x) return y<n.y;
		return x<n.x;
	}
} A[N],B[N];
void R(int &x) {
	x=0;ch=getchar();
	while (ch<'0' || '9'<ch) ch=getchar();
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
}
void W(ll x) {
	if (x>=10) W(x/10);
	putchar(x%10+'0');
}
int main() {
	R(n);
	ma=0;mi=oo;
	ans=(ll) mi*mi;
	for (i=1;i<=n;i++) {
		R(A[i].x);R(A[i].y);
		if (A[i].x>A[i].y) {
			t=A[i].x;A[i].x=A[i].y;A[i].y=t;
		}
		if (A[i].y>ma) ma=A[i].y,tma=i;
		if (A[i].x<mi) mi=A[i].x,tmi=i;
	}
	for (i=1;i<=n;i++) if (i!=tma && i!=tmi) B[++m]=A[i];
	sort(B+1,B+m+1);
	Rmax=ma;Bmin=mi;
	Bmax=A[tma].x;
	Rmin=A[tmi].y;
	for (i=1;i<=m;i++) {
		Rmin=min(Rmin,B[i].y);
		Bmax=max(Bmax,B[i].x);
	}
	ans=min(ans,(ll) (Rmax-Rmin)*(Bmax-Bmin));
	if (tma!=tmi) {
		Rmax=ma;Rmin=mi;
		Bmax=max(A[tma].x,A[tmi].y);
		Bmin=min(A[tma].x,A[tmi].y);
		sma=0;smi=oo;
		for (i=1;i<m;i++) {
			sma=max(sma,B[i].y);
			smi=min(smi,B[i].y);
			ans=min(ans,(ll) (Rmax-Rmin)*(max(Bmax,max(sma,B[m].x))-min(Bmin,min(smi,B[i+1].x))));
		}
		ans=min(ans,(ll) (Rmax-Rmin)*(max(Bmax,B[m].x)-min(Bmin,B[1].x)));
		sma=max(sma,B[m].y);
		smi=min(smi,B[m].y);
		ans=min(ans,(ll) (Rmax-Rmin)*(max(Bmax,sma)-min(Bmin,smi)));
	}
	W(ans);puts("");
}