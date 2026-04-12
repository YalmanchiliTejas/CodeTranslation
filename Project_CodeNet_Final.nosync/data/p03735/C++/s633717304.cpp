#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 400010
#define ll long long
#define inf 2147483647
using namespace std;
struct aa{int x, y;}a[N];
int n, b[N], mnp, mxp, mn, mx, l, x1, x2, now;
ll ans;
inline bool cmp(aa a, aa b){return a.x<b.x;}
int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){scanf("%d%d", &a[i].x, &a[i].y); if(a[i].x>a[i].y)swap(a[i].x, a[i].y);}
	mnp=mxp=1;
	for(int i=2; i<=n; i++){
		if(a[i].x<a[mnp].x)mnp=i;
		if(a[i].y>a[mxp].y)mxp=i;
	}
	mx=a[mnp].x; mn=a[mxp].y;
	for(int i=1; i<=n; i++){mx=max(mx, a[i].x); mn=min(mn, a[i].y);}
	ans=(ll)(mx-a[mnp].x)*(a[mxp].y-mn);
	if(mnp==mxp){printf("%lld", ans); return 0;}
	x1=a[mxp].y-a[mnp].x; a[mnp].x=a[mnp].y; a[mxp].y=a[mxp].x;
	l=0; for(int i=1; i<=n; i++){b[++l]=a[i].x; b[++l]=a[i].y;}
	sort(b+1, b+1+l); sort(a+1, a+1+n, cmp);
	mn=a[1].y; for(int i=2; i<=n; i++)mn=min(mn, a[i].y);
	mx=a[1].x; for(int i=2; i<=n; i++)mx=max(mx, a[i].x);
	x2=inf; now=0;
	for(int i=1; i<=l&&b[i]<=mn; i++){
		while(now<n&&a[now+1].x<b[i]){now++; mx=max(mx, a[now].y);}
		x2=min(x2, mx-b[i]);
	}
	ans=min(ans, (ll)x1*x2); printf("%lld", ans);
	return 0;
}