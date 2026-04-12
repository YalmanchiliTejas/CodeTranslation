#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)(1e18)

signed main(){
	int N, i;
	scanf("%lld", &N);
	vector<int> A(N + 2, 0);
	for(i = 2; i < N + 2; i++){
		scanf("%lld", &A[i]);
	}
	vector<int> odd_sum(N / 2 + 1, 0), sub_sum(N / 2 + 1, 0), sub_sum_max(N / 2 + 1, 0);
	for(i = 1; i <= N / 2; i++){
		odd_sum[i] = odd_sum[i - 1] + A[2 * i + 1];
		sub_sum[i] = sub_sum[i - 1] + A[2 * i] - A[2 * i + 1];
		sub_sum_max[i] = max(sub_sum_max[i - 1], sub_sum[i]);
	}
	int ans = -inf;
	if(N % 2 == 0){
		ans = odd_sum[N / 2] + sub_sum_max[N / 2];
	}
	else{
		int now = 0;
		for(i = N / 2; i >= 0; i--){
			ans = max(ans, odd_sum[i] + sub_sum_max[i] + now);
			now += A[2 * i + 2];
		}
	}
	printf("%lld\n", ans);
	return 0;
}