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

long long int func(string s, string t, int to) {
	long long int ret = 0;
	vector<vector<long long int>>sum(s.size() + 1, vector<long long int>(3));
	vector<vector<long long int>>num(s.size() + 1, vector<long long int>(3));
	num[0][2] = 1;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 3; j++) {
			if (i + t.size() <= s.size()) {
				if (j == 0) {
					sum[i + t.size()][0] += num[i][j];
					sum[i + t.size()][0] %= MOD;
				}
				else if (j == 1) {
					if (s.substr(i, t.size()) > t) {
						sum[i + t.size()][0] += num[i][j];
						sum[i + t.size()][0] %= MOD;
					}
					else if (s.substr(i, t.size()) == t) {
						sum[i + t.size()][1] += num[i][j];
						sum[i + t.size()][1] %= MOD;
					}
				}
				else {
					if (t != "0") {
						if (i == 0) {
							if (s.substr(i, t.size()) > t) {
								sum[i + t.size()][0] += num[i][j];
								sum[i + t.size()][0] %= MOD;
							}
							else if (s.substr(i, t.size()) == t) {
								sum[i + t.size()][1] += num[i][j];
								sum[i + t.size()][1] %= MOD;
							}
						}
						else {
							sum[i + t.size()][0] += num[i][j];
							sum[i + t.size()][0] %= MOD;
						}
					}
				}
			}
			for (int k = '0'; k <= '9'; k++) {
				if (j == 1 && s[i] < k)continue;
				if (i == 0 && j == 2 && s[i] < k)continue;
				if (j <= 1) {
					num[i + 1][j && (s[i] == k)] += num[i][j];
					num[i + 1][j && (s[i] == k)] %= MOD;
					sum[i + 1][j && (s[i] == k)] += sum[i][j];
					sum[i + 1][j && (s[i] == k)] %= MOD;
				}
				else {
					if (k == '0') {
						num[i + 1][2] += num[i][j];
						num[i + 1][2] %= MOD;
						sum[i + 1][2] += sum[i][j];
						sum[i + 1][2] %= MOD;
					}
					else {
						if (i == 0) {
							num[i + 1][(s[i] == k)] += num[i][j];
							num[i + 1][(s[i] == k)] %= MOD;
							sum[i + 1][(s[i] == k)] += sum[i][j];
							sum[i + 1][(s[i] == k)] %= MOD;
						}
						else {
							num[i + 1][0] += num[i][j];
							num[i + 1][0] %= MOD;
							sum[i + 1][0] += sum[i][j];
							sum[i + 1][0] %= MOD;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i <= to; i++) {
		ret += sum.back()[i];
	}
	ret %= MOD;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b, c;
	cin >> a >> b >> c;
	long long int ans = func(b, c, 1) + MOD - func(a, c, 0);
	if (a == "0"&&c == "0")ans++;
	cout << ans % MOD << endl;
}
