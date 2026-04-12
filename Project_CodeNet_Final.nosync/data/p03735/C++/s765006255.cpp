#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define x first
#define y second

using namespace std;

pair<int, int> a[222222];
long long an;
int n;

int main(){
//	freopen("input.inp", "r", stdin);
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) scanf("%d%d",&a[i].x,&a[i].y);
	for(int i = 1; i <= n; ++i) if (a[i].x < a[i].y) swap(a[i].x, a[i].y);
	int mn1 = 1e9, mx1 = 0, mn2 = 1e9, mx2 = 0;
	int mx = 1, mn = 1;
	for(int i = 1; i <= n; ++i){
		mx2 = max(mx2, a[i].x);
		mn2 = min(mn2, a[i].x);
		mn1 = min(mn1, a[i].y);
		mx1 = max(mx1, a[i].y);
		if (a[mx].x < a[i].x) mx = i;
		if (a[mn].y > a[i].y) mn = i;
	}
	an = 1ll * (mx2 - mn2) * (mx1 - mn1);
	if (mx != mn && n > 2){
		vector<pair<int, int> > v;
		for(int i = 1; i <= n; ++i) if (i != mx && i != mn)	v.pb(a[i]);
		sort(v.begin(), v.end());
		int low = min(a[mx].y, min(a[mn].x, v[0].x));
		int high = max(a[mx].y, a[mn].x);
		for(int i = v.size() - 1; i >= 0; --i){
			if (v[i].x <= high) break;
			an = min(an, 1ll * (v[i].x - low) * (a[mx].x - a[mn].y));
			low = min(low, v[i].y);
			high = max(high, v[i].y);
		}
		an = min(an, 1ll * (high - low) * (a[mx].x - a[mn].y));
	}
	printf("%lld",an);
	return 0;
}