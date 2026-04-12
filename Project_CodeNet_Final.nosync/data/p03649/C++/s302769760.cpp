#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 55;
LL a[maxn], n, d, k, limit, ans;

bool cmp(LL a, LL b){
	return a > b;
}

int main(){
	scanf("%lld", &n); limit = n-1;
	for (LL i=1; i<=n; i++) scanf("%lld", &a[i]);
	sort(a+1, a+n+1, cmp);
	for (LL i=1; i<=n-1; i++){
		sort(a+1, a+i+1, cmp);
		d = a[1] - a[i+1];
		if (d >= n+2){
			k = d/(n+1);
			ans += i*k;
			limit -= i*k;
			for (LL j=1; j<=i; j++)
				a[j] -= k*(n+1);
		}
	}
	sort(a+1, a+n+1, cmp);
	d = a[n] - limit;
	if (d > 0){
		ans += d*n;
		for (LL i=1; i<=n; i++) a[i] -= d;
	}
	while (a[1] > limit){
		ans++;
		a[1] -= n+1;
		limit--;
		sort(a+1, a+n+1, cmp);
	}
	printf("%lld\n", ans);
	return 0;
}