#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

int n;
ll arr[maxn], sum[maxn];

int main() {
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; ++i) scanf("%lld", arr + i);
		sort(arr + 1, arr + 1 + n);
		for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + arr[i];
		if(n & 1) {
			if(n == 3) {
				ll ans = max((arr[3] - arr[1] + arr[2] - arr[1]), (arr[3] - arr[1] + arr[3] - arr[2]));
				printf("%lld\n", ans);
			} else{
				ll ans1 = 2ll * ((sum[n] - sum[n / 2 + 1]) - (sum[n / 2 - 1])) - (arr[n / 2 + 1] + arr[n / 2]);
				ll ans2 = 2ll * ((sum[n] - sum[n / 2 + 2]) - (sum[n / 2])) + (arr[n / 2 + 2] + arr[n / 2 + 1]);
				printf("%lld\n", max(ans1, ans2));
			}
		} else {
			ll ans = 2ll * ((sum[n] - sum[n / 2 + 1]) - (sum[n /  2 - 1])) + (arr[n / 2 + 1] - arr[n / 2]);
			printf("%lld\n", ans); 
		}
	}
	return 0;
}