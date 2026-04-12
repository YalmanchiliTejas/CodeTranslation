#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct ddd{
	int s, b;
}num[222222];
int N;
bool cmp(struct ddd x, struct ddd y){
	return x.s < y.s;
}
int main(){
	cin>>N;
	int x, y;
	int mi = 0, ma = 1e9, mmi = 1e9, mma = 0;
	for(int i = 1;i <= N; i++){
		scanf("%d%d", &x, &y);
		num[i].s = min(x, y);
		num[i].b = max(x, y);
		mi = max(mi, min(x, y));
		ma = min(ma, max(x, y));
		mmi = min(mmi, min(x, y));
		mma = max(mma, max(x, y));
	}
	sort(num + 1, num + 1 + N, cmp);
	LL ans = 1LL * (1LL * mma - 1LL * ma) * (1LL * mi - 1LL * mmi);
	ma = mi = num[1].b;
	for(int i = 1;i < N; i++){
		ans = min(ans, 1LL * (1LL * mma - 1LL * mmi) * (1LL * max(ma, num[N].s) - 1LL * min(mi, num[i+1].s)));
		mi = min(mi, num[i+1].b);
		ma = max(ma, num[i+1].b);
	}
	printf("%lld\n", ans);
	return 0;
}