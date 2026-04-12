#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int maxn = 3010;

ll nums[maxn];
ll dp[maxn][maxn];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
	}

	for (int sz = 1; sz <= N; sz++) {
		for (int st = 1; st <= N; st++) {
			int ce = st + sz-1;
			if (ce > N) break;
			if (st == ce) dp[st][ce] = nums[st];
			else {
				dp[st][ce] = max(0-dp[st+1][ce] + nums[st],
					0-dp[st][ce-1] + nums[ce]);
			}

		}
	}

	cout << dp[1][N] << endl;

}