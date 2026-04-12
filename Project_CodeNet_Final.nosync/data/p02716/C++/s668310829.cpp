#include <cassert>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;
using lint = long long;
constexpr int MOD = 1000000007, INF = 1010101010;
constexpr lint LINF = 1LL << 61;

template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
	for (const auto &e : vec) os << e << (&e == &vec.back() ? "\n" : " ");
	return os;
}

template<class T>
inline bool chmax(T &a, const T b) { return a < b && (a = b, true); }

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	vector<vector<lint>> dp(N + 4, vector<lint>(2, -LINF));
	dp[0][0] = -A[0];
  	dp[0][1] = dp[1][1] = 0;
  	dp[1][0] = -A[1];

	for (int i = 0; i < N; i++) {
		
		chmax(dp[i + 2][0], dp[i][0] + A[i]);
		chmax(dp[i + 2][0], dp[i][1] + 0   );
		chmax(dp[i + 2][1], dp[i][1] + A[i]);

		if (i & 1) {
			chmax(dp[i + 3][0], dp[i][1] + A[i]);
		}
		else {
			chmax(dp[i + 3][0], dp[i][0] + A[i]);
			chmax(dp[i + 3][0], dp[i][1] + 0);
			chmax(dp[i + 3][1], dp[i][1] + A[i]);
          	chmax(dp[i + 4][0], dp[i][1] + A[i]);
		}

	}

	lint ans = -LINF;
  	bool offset = N & 1;
	chmax(ans, dp[N + 0 - offset][1]);	
  	chmax(ans, dp[N + 1 - offset][1]);	
  	chmax(ans, dp[N + 2 - offset][0]);	
  	chmax(ans, dp[N + 3 - offset][0]);

	cout << ans << endl;


	return 0;
}
