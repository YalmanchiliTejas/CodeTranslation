#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const double PI = 2 * acos(0);
int N;
int arr[200001];
LL dp[200001][3];

LL rek(int idx, int jatah) {
	if (idx >= N) return 0;
	if (dp[idx][jatah] == -1) {
		if (jatah > 0) {
			dp[idx][jatah] = max(rek(idx + 1, jatah - 1), rek(idx + 2, jatah) + arr[idx]);
		} else dp[idx][jatah] = rek(idx + 2, jatah) + arr[idx];
	}
	return dp[idx][jatah];
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	LL ans = rek(0, 1 + (N % 2));
	printf("%lld\n", ans);
}