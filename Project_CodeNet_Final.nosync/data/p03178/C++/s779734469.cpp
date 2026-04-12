#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int MOD = 1e9 + 7;
const int N = (1e4) + 5;
int memo[N][2][100];
string s;
int D;

int DP(int pos, int low, int sum) {
	if (pos == s.size()) return sum == 0;
	int &ret = memo[pos][low][sum];
	if (ret != -1) return ret;
	ret = 0;
	if (low) {
		for (int i = 0; i <= 9; ++i) {
			ret = (ret + DP(pos + 1, 1, (sum + i) % D)) % MOD;
		}
	} else {
		int d = s[pos] - '0';
		for (int i = 0; i <= d; ++i) {
			ret = (ret + DP(pos + 1, i < d? 1 : 0, (sum + i) % D)) % MOD;
		}
	}
	return ret;
}

int main() {
	getline(cin, s);
	scanf("%d", &D);
	memset(memo, -1, sizeof memo);
	int ans = (DP(0, 0, 0) - 1 + MOD) % MOD;//
	printf("%d\n", ans);
	return 0;
}