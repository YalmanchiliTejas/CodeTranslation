#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k, rec, rem;
	long long ans;
	scanf("%d %d",&n,&k);
	if (k == 0){
		printf("%lld\n", 1LL * n * n);
		return 0;
	}
	ans = 0;
	for (int i = k + 1; i <= n; i++){
		rec = n / i;
		rem = n % i;
		ans += 1LL * rec * (i - k) + max(rem - k + 1, 0);
	}
	printf("%lld\n", ans);
	return 0;
}