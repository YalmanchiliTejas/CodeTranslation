#include<cstdio>
using namespace std;
const int N=100100;
int i,j,k,n,ch,ff,x,y,En;
int f[N],h[N];
struct edge { int s,n;} E[N<<1];
void R(int &x) {
	ff=x=0;ch=getchar();
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x=-x;
}
void E_add(int x,int y) {
	E[++En].s=y;E[En].n=h[x];h[x]=En;
	E[++En].s=x;E[En].n=h[y];h[y]=En;
}
void dfs(int x,int F) {
	int n1=0;
	for (int k=h[x];k;k=E[k].n) if (E[k].s!=F) {
		dfs(E[k].s,x);
		if (f[E[k].s]==-1) f[x]=-1;
		if (f[E[k].s]==1) n1++;
	}
	if (f[x]==-1) return;
	if (n1>1) f[x]=-1;
	else f[x]=n1^1;
}
int main() {
	R(n);
	for (i=1;i<n;i++) {
		R(x);R(y);
		E_add(x,y);
	}
	dfs(1,0);
	if (f[1]==0) puts("Second");
	else puts("First");
}