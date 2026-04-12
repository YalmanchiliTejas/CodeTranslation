#include<cstdio>
using namespace std;
typedef long long ll;
const int N=400400;
int i,j,k,n,m,ch,ff,l,r,x;
int a[N];
void R(int &x) {
	ff=x=0;ch=getchar();
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x=-x;
}
void R(ll &x) {
	ff=x=0;ch=getchar();
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x=-x;
}
void W(int x) {
	if (x>=10) W(x/10);
	putchar(x%10+'0');
}
void W(ll x) {
	if (x>=10) W(x/10);
	putchar(x%10+'0');
}
int main() {
	R(n);
	R(a[n]);
	l=n;r=n;
	for (i=2;i<=n;i++) {
		R(x);
		if (l<=r) a[++r]=x;
		else a[--r]=x;
		int t=l;l=r;r=t;
	}
	if (l<=r) {
		for (i=l;i<=r;i++) W(a[i]),putchar(' ');
	}
	else {
		for (i=l;i>=r;i--) W(a[i]),putchar(' ');
	}
	puts("");
}