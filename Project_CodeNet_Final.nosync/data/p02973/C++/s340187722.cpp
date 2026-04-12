
// E - Sequence Decomposing

// 実質的に、最長広義単調減少部分列を求める問題

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int A[100000];
int dp[100001]; // 長さがiであるような広義単調減少列における最終要素の最大値

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	fill(dp, dp+N+1, -1);
	dp[0] = INF;

	int ans = 0;
	for (int i=0; i<N; i++) {
		int j = upper_bound(dp, dp+N+1, A[i], std::greater<int>()) - dp;
		dp[j] = A[i];
		ans = max(ans, j);
	}

	cout << ans << endl;

	return 0;
}