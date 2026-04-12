#include <bits/stdc++.h>
#define rep(i, n) for (rint i = 1; i <= (n); i ++)
#define re0(i, n) for (rint i = 0; i < (int) n; i ++)
#define travel(i, u) for (rint i = head[u]; i; i = e[i].nxt)
#define rint int
using namespace std;
     
typedef long long lo;
     
template<typename tp> inline void read(tp &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; c < '0' || c > '9'; f |= c == '-', c = getchar());
	for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
	if (f) x = -x;
}
namespace {
    const int mo = 1e9 + 7;
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

const int N = 3e5 + 23;
int n, m;
char str[N];

inline int spj() {
	int ans = 0;
	for (int fi = 0; fi < 2; fi++) {
		vector <vector <int> > dp(n + 1, vector <int> (2, 0));
		dp[1][fi] = 1;
		for (int i = 2; i <= n; i++) {
			U(dp[i][0], dp[i - 1][1]);
			U(dp[i][0], dp[i - 1][0]);
			U(dp[i][1], dp[i - 1][0]);
			// cout << dp[i][0] << " " << dp[i][1] << "\n";
		}
		if (fi == 0) ans = add(ans, add(dp[n][0], dp[n][1]));
		else ans = add(ans, dp[n][0]);
	}
	return ans;
}

inline int doit(int limit) {
	++limit;
	vector <int> dp(n + 1, 0);
	vector <int> sum(n + 1, 0);
	dp[0] = sum[0] = 1;
	for (int i = 1; i <= n; i++) {
		auto getsum = [&](int l, int r) {
			if ((l & 1) != (r & 1)) ++l;
			if (l > r || r < 0) return 0;
			else return sub(sum[r], l >= 2 ? sum[l - 2] : 0);
		};
		// for (int k = i - 2; k >= 0 && k >= i - limit; k -= 2)
		// 	U(dp[i], dp[k]);
		U(dp[i], getsum(max(0, i - limit), i - 2));
		sum[i] = dp[i];
		if (i > 1) U(sum[i], sum[i - 2]);
	}
	int ans = 0;
	for (int pre = 2; pre <= limit; pre += 2) {
		U(ans, mul(pre, dp[n - pre]));
	}
	return ans;
}

int main(void) {
	read(n); read(m);
	scanf("%s", str + 1);
	int first = 0;
	for (int i = 1; i <= m; i++) 
		if (str[i] != str[1]) { first = i; break; }
	if (first == 0) {
		cout << spj() << "\n";
		return 0;
	}
	--first;
	while (m && str[m] == str[1]) --m;
	// cout << "first = " << first << "\n";
	int limit = first & 1 ? first : first + 1;
	int con = limit;
	for (int i = first + 1; i <= m; i++) {
		if (str[i] != str[1]) {
			if (con & 1) limit = min(limit, con);
			con = 0;
		} else {
			++con;
		}			   
	}
	if (con & 1) limit = min(limit, con);
	cerr << "limit = " << limit << "\n";
	cout << doit(limit) << "\n";
}
