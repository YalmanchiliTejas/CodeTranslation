#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
const int INF = 1e9 + 1;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;


int main(){
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
	for (int i = 1; i <= N; ++i){
		for (int j = 0; i + j <= N; ++j){
			if ((N - i) % 2 == 0)
				dp[j][i + j] = max(dp[j + 1][i + j] + a[j], dp[j][i + j - 1] + a[i + j - 1]);
			else
				dp[j][i + j] = min(dp[j + 1][i + j] - a[j], dp[j][i + j - 1] - a[i + j - 1]);
		}
	}

	cout << dp[0][N] << endl;
	return 0;
}