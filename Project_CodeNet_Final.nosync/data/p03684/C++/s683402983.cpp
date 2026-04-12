#include <cstdio>
#include <algorithm>
#define N 200010
using namespace std;
typedef long long ll;
ll n, ans, pr[N];
struct st{ll x, y, z;} a[N/2], b[N];

bool cmp1(st p, st q) {return p.x<q.x;}
bool cmp2(st p, st q) {return p.y<q.y;}
bool cmp3(st p, st q) {return p.z<q.z;}
ll f(ll p) {
	if(pr[p]==p) return p;
	return pr[p] = f(pr[p]);
}

int main() {
	ll i, x, y;
	scanf("%lld", &n);
	for(i=1; i<=n; i++) scanf("%lld%lld", &a[i].x, &a[i].y), a[i].z=pr[i]=i;
	sort(a+1, a+n+1, cmp1);
	for(i=1; i<n; i++) b[i] = {a[i].z, a[i+1].z, a[i+1].x-a[i].x};
	sort(a+1, a+n+1, cmp2);
	for(i=1; i<n; i++) b[i+n-1] = {a[i].z, a[i+1].z, a[i+1].y-a[i].y};
	sort(b+1, b+2*n-1, cmp3);
	for(i=1; i<2*n-1; i++) {
		x = f(b[i].x), y = f(b[i].y);
		if(x!=y) ans += b[i].z, pr[y] = x;
	}
	printf("%lld", ans);
	return 0;
}