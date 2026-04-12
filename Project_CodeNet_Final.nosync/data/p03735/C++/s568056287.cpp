#include<cstdio>
#include<cstring>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef long long LL;

const int maxn = 200009;
pair<int,int> a[maxn];
int n, tmp, _mx, _mn, mx, mn, best; 
LL ans = 1e18;

int main(){
	scanf("%d", &n);
	if (n == 1) { puts("0"); return 0; }
	a[0].x = 1e9 + 1;
	for (int i=1; i<=n; i++){
		scanf("%d%d", &a[i].x, &a[i].y);
		if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
	}
	sort(a+1, a+n+1);
	for (int i=1; i<=n; i++)
		if (a[i].x <= a[_mn].x && a[i].y >= a[_mx].y) _mn = _mx = i;
		else if (a[i].x < a[_mn].x) _mn = i;
		else if (a[i].y > a[_mx].y) _mx = i;
	mn = 1e9 + 1;
	for (int i=1; i<=n; i++){
		mn = min(mn, a[i].y);
		mx = max(mx, a[i].x);
	}
	ans = 1LL * (mx-a[_mn].x) * (a[_mx].y-mn);
	if (_mn != _mx){
		best = 1e9 + 1; mn = mx = a[1].y;
		for (int i=2; i<=n; i++){
			best = min(best, max(a[n].x, mx) - min(a[i].x, mn));
			mn = min(mn, a[i].y);
			mx = max(mx, a[i].y);
		}
		ans = min(ans, 1LL * best * (a[_mx].y - a[_mn].x));
	}
	printf("%lld\n", ans);
	return 0;
}