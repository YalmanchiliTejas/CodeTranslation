#include <bits/stdc++.h>
#define rep(i, n) for (rint i = 1; i <= (n); i ++)
#define re0(i, n) for (rint i = 0; i < (int) n; i ++)
#define travel(i, u) for (rint i = head[u]; i; i = e[i].nxt)
#define rint register int
using namespace std;
 
typedef long long lo;
 
template<typename tp> inline void read(tp &x) {
    x = 0; char c = getchar(); int f = 0;
    for (; c < '0' || c > '9'; f |= c == '-', c = getchar());
    for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
    if (f) x = -x;
}

namespace {
	int mo;
    inline int add(int x, int y) { x += y; return x >= mo ? x - mo : x; }
    inline int sub(int x, int y) { x -= y; return x < 0 ? x + mo : x; }
    inline int mul(int x, int y) { return (lo) x * y % mo; }
    inline int power(int a, int k = mo - 2) {
		int ans = 1;
		for (; k; k >>= 1, a = mul(a, a))
			if (k & 1) ans = mul(ans, a);
		return ans;
    }
	inline void U(int &x, int y) { x = add(x, y); } 
}

const int N = 3333;
int n, C[N][N], p2[N], dp[N][N];

inline int calc(int S) {
	int other = power(2, n - S);
	{
		int ans = 0;
		re0 (i, S + 1) U(ans, mul(power(other, i), dp[S][i]));
		return ans;
	}
	vector <int> dp(S + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= S; i++) {
		vector <int> new_dp(S + 1, 0);
		for (int j = 0; j <= S; j++)
			if (dp[j]) {
				U(new_dp[j], mul(j + 1, dp[j]));
				U(new_dp[j + 1], mul(other, dp[j]));
			}
		swap(dp, new_dp);
	}
	int ans = 0;
	for (int &i : dp) U(ans, i);
	return ans;
}

int main(void) {
	read(n); read(mo);
	re0 (i, n + 1) C[i][0] = 1;
	rep (i, n) rep (j, i) C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
	dp[0][0] = 1;
	rep (i, n) {
		re0 (j, i + 1) if (dp[i - 1][j]) {
			U(dp[i][j], mul(j + 1, dp[i - 1][j]));
			U(dp[i][j + 1], mul(1, dp[i - 1][j]));
		}
	}
	// cout << C[4][2] << "\n";
	p2[0] = 1;
	rep (i, n) p2[i] = (lo) p2[i - 1] * 2 % (mo - 1);
	int ans = 0;
	for (int S = 0; S <= n; S++) {
		int ways = calc(S);
		U(ans, mul(mul(C[n][S], S & 1 ? mo - 1 : 1), mul(power(2, p2[n - S]), ways)));
	}
	cout << ans << "\n";
}
