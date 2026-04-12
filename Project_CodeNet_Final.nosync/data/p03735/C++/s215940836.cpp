//Created Time:2019年12月23日 星期一 18时50分17秒
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define pi pair < int , int >
#define N 200005
#define fi first
#define se second
#define oo 999999999999999999

using namespace std;

int n;
pi b[N];

int main(){
	scanf("%d", &n); int mx = 0, mn = 999999999;
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &b[i].fi, &b[i].se);
		if(b[i].fi > b[i].se) swap(b[i].fi, b[i].se);
		mx = max(mx, b[i].se); mn = min(mn, b[i].fi);
	}
	//Case1 mx -> R, mn -> R
	//Case2 mx -> R, mn -> B
	long long ans1 = oo, ans2 = oo;
	int l2 = mx, r2 = mn, l1 = 999999999, r1 = 0;
	sort(b + 1, b + 1 + n);
	for(int i = 1; i <= n; ++i){
		l2 = min(l2, b[i].se); r2 = max(r2, b[i].fi);
		ans1 = min(ans1, 1ll * (mx - mn) * (max(b[n].fi, r1) - min(b[i].fi, l1)));
		l1 = min(l1, b[i].se); r1 = max(r1, b[i].se);
	}
	ans2 = 1ll * (mx - l2) * (r2 - mn);
	cout << min(ans1, ans2) << endl;
	return 0;
}
