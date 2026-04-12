#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int N, S;
int A[3000 + 10];

ll dp[3000 + 10][3000 + 10];//0->まだ取り始めていない　1->Lが決まっていて、Rが未定 2->LもRも決まってる

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++)cin >> A[i];

	ll ans = 0;
	for (int i = 0; i <= N; i++)dp[i][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < S; j++) {
			(dp[i + 1][j] += dp[i][j]) %= MOD;
			if (j + A[i] < S) {
				(dp[i + 1][j + A[i]] += dp[i][j]) % MOD;
			}
			if (j + A[i] == S) {
				(ans += dp[i][j] * (N - i)) %= MOD;
			}
		}
	}
	cout << ans << endl;
	return 0;
}