#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const LL MAXN = 8e5 + 5;
struct balls{
	LL x, node;
}a[MAXN + MAXN];
LL ok[MAXN];
LL dif(LL n){
	LL min1 = 0x7f7f7f7f, min2 = 0x7f7f7f7f, max1 = 0, max2 = 0;
	for(LL i = 0 ; i < n << 1 ; i += 2){
		LL k1 = min(a[i].x, a[i + 1].x), k2 = max(a[i].x, a[i + 1].x);
		min1 = min(min1, k1);
		max1 = max(max1, k1);
		min2 = min(min2, k2);
		max2 = max(max2, k2);
	}
	return (max1 - min1) * (max2 - min2);
}
bool cmp(balls y, balls z){
	return y.x < z.x;
}
LL same(LL n, LL r1, LL r2){
	LL sum = 0, i;
	for(i = 1 ; i <= n ; ++i)
		sum += i;
	LL mmin = min(r1 & 1 ? a[r1 - 1].x : a[r1 + 1].x, r2 & 1 ? a[r2 - 1].x : a[r2 + 1].x),
	   mmax = max(r1 & 1 ? a[r1 - 1].x : a[r1 + 1].x, r2 & 1 ? a[r2 - 1].x : a[r2 + 1].x);
	sum -= r1 / 2 + r2 / 2 + 2;
	ok[r1 / 2 + 1] = ok[r2 / 2 + 1] = 3;
	sort(a , a + 2 * n, cmp);
	LL l = 0, r = 0, ans = 0x7f7f7f7f7f7f7f7f;
	while(r < n << 1 && l < n << 1){
		if(!sum){
			ans = min(ans, max(mmax, a[r - 1 >= 0 ? r - 1 : 800000].x) - min(mmin, a[l].x));
			if(ok[a[l].node] == 1) sum += a[l].node;
			--ok[a[l].node];
			++l;
		}
		if(ok[a[l].node] >= 2) --ok[a[l].node], ++l;
		if(sum){
			if(!ok[a[r].node])
				sum -= a[r].node;
			++ok[a[r].node];
			++r;
		}
	}
	return ans;
}
int main(){
	LL n, i, mmin = 0x7f7f7f7f7f7f7f7f, mmax = 0, r1, r2, ans = 0x7f7f7f7f7f7f7f7f;
	scanf("%lld", &n);
	for(i = 0 ; i < n << 1 ; ++i){
		scanf("%lld", &a[i].x);
		a[i].node = i / 2 + 1;
		if(a[i].x > mmax){
			mmax = a[i].x;
			r1 = i;
		}
		if(a[i].x < mmin){
			mmin = a[i].x;
			r2 = i;
		}
	}
	ans = dif(n);
	if(r1 + 1 != r2 && r2 + 1 != r1)
		ans = min(ans, same(n, r1, r2) * (mmax - mmin));
	printf("%lld\n", ans);
	return 0;
}