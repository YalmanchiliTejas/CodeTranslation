#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int N, i, j;
	scanf("%lld", &N);
	vector<int> s(N);
	for(i = 0; i < N; i++){
		scanf("%lld", &s[i]);
	}
	int ans = 0;
	for(i = 1; i < N; i++){
		int now = 0;
		for(j = 1; i * j < N - 1 - i && i * j != N - 1 - i * j && i * (j - 1) != N - 1 - i * j; j++){
			now += s[i * j] + s[N - 1 - i * j];
//			printf("now(%lld, %lld) = %lld\n", i, j, now);
			ans = max(ans, now);
		}
	}
	printf("%lld\n", ans);
	return 0;
}