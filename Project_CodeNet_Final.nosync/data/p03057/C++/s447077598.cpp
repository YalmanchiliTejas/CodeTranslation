#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	string s;
	cin >> s;
	set<char>st;
	for (auto i : s)st.insert(i);
	if (st.size() == 1) {
		vector<long long int>dp(N + 1);
		dp[0] = 1;
		for (int i = 1; i <= N; i++) {
			dp[i] = dp[i - 1];
			if (i > 1)dp[i] += dp[i - 2];
			dp[i] %= MOD;
		}
		long long int ans = dp.back();
		dp[0] = 1;
		dp[1] = 0;
		for (int i = 2; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
			dp[i] %= MOD;
		}
		ans += dp.back();
		ans %= MOD;
		cout << ans << endl;
		return 0;
	}
	s.push_back(s[0] + 1);
	vector<int>num(s.size() + 1);
	for (int i = 0; i <= s.size(); i++) {
		num[i] = s[i] == s[0];
		if (i)num[i] = num[i] * (num[i - 1] + 1);
	}
	int fst = 0;
	int m = MOD;
	bool even = true;
	for (int i = 1; i < s.size()-1; i++) {
		if (!num[i] && num[i - 1]) {
			if (num[i - 1] & 1) {
				even = false;
				m = min(m, num[i - 1]);
			}
			if (fst == 0) {
				fst = num[i - 1];
				if (fst % 2 == 0)m = MOD;
			}
		}
	}
	if (even) {
		m = fst + 2;
	}
	else if (fst % 2 == 0) {
		m = min(m, fst+2);
	}
	if (m & 1)m++;
	//cout << m << endl;
	vector<long long int>dp(N + 2);
	vector<long long int>sum(N + 2);
	for (int i = 2; i <= m; i += 2)dp[i] = i;
	for (int i = 2; i <= N; i++) {
		dp[i] += sum[i - 2] + MOD;
		if (i - m - 2 >= 0)dp[i] -= sum[i - m - 2];
		dp[i] %= MOD;
		if (i == N) {
			cout << dp[i] << endl;
			return 0;
		}
		sum[i] = sum[i - 2] + dp[i];
		sum[i] %= MOD;
	}
}
