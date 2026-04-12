// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

int read() {
	int X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

const int N=200000+10;

int n;
struct node { int x,y; } a[N];

ll yui() {
	int rmin=1e9,rmax=0,bmin=1e9,bmax=0;
	for (int i=1;i<=n;++i) {
		rmin=min(rmin,a[i].x),rmax=max(rmax,a[i].x);
		bmin=min(bmin,a[i].y),bmax=max(bmax,a[i].y);
	}
	return 1ll*(rmax-rmin)*(bmax-bmin);
}

ll ui() {
	sort(a+1,a+n+1,[](node p,node q) { return p.x<q.x;} );
	int rmin=a[1].x,rmax=0,bmin=1e9,bmax=0,minb=1e9;
	for (int i=1;i<=n;++i) rmax=max(rmax,a[i].y);
	for (int i=1;i<=n;++i) {
		bmin=min(bmin,a[i].y),bmax=max(bmax,a[i].y);
		minb=min(minb,max(a[n].x,bmax)-min(a[i+1].x,bmin));
	}
	return 1ll*(rmax-rmin)*minb;
}

int main() {
	n=read();
	for (int i=1;i<=n;++i) {
		a[i].x=read(),a[i].y=read();
		if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
	}
	printf("%lld\n",min(yui(),ui()));
	return 0;
}