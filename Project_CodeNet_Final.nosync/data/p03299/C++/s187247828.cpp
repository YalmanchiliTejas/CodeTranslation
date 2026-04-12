#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105, mod = 1e9+7, inv2 = (mod+1)/2, phi = mod-1;

int n, a[MAXN], dp[MAXN][MAXN][2];

inline int power(int a, int n)
{
	int ans = 1;
	for (; n; n >>= 1) {
		if (n&1) ans = (long long)ans*a%mod;
		a = (long long)a*a%mod;
	}
	return ans;
}

void dfs(int L, int R)
{
	int pos = L, tmp;
	for (int i = L; i <= R; i++)
		if (a[i] < a[pos])
			pos = i;
	tmp = a[pos];
        for (int i = L; i <= R; i++)
		a[i] -= tmp;
	int cnt_len = 0, cnt_cnt = 0;
	for (int i = L; i <= R; i++)
		if (a[i] == 0)
			cnt_cnt++;
	if (cnt_cnt == R-L+1) {
		dp[L][R][0] = power(2, tmp);
		dp[L][R][1] = ((power(2, R-L+1)-2)%mod+mod)%mod;
		// cerr << L << " " << R << " " << dp[L][R][0] << " " << dp[L][R][1] << endl;
		return;
	}
	int cnt_sub = 0;
	dp[L][R][0] = dp[L][R][1] = 1;
	for (int i = L; i <= R; ) {
		if (a[i] == 0) {
			int j = i;
			while (j+1 <= R && a[j+1] == 0) j++;
			cnt_len++;
			i = j+1;
		} else {
			int j = i;
			while (j+1 <= R && a[j+1] != 0) j++;
			cnt_sub++;
			dfs(i, j);
			dp[L][R][0] = (long long)dp[L][R][0]*dp[i][j][0]%mod;
			dp[L][R][1] = (long long)dp[L][R][1]*((dp[i][j][0]*2ll+dp[i][j][1])%mod)%mod;
		}
	}
	dp[L][R][0] = (long long)dp[L][R][0]*2%mod;
	dp[L][R][1] = (long long)dp[L][R][1]*power(2, cnt_cnt)%mod;
	dp[L][R][1] = ((dp[L][R][1]-dp[L][R][0])%mod+mod)%mod;
	dp[L][R][0] = (long long)dp[L][R][0]*power(2, tmp-1)%mod;
	// cerr << L << " " << R << " " << dp[L][R][0] << " " << dp[L][R][1] << endl;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 1) {
		cout << power(2, a[1]) << endl;
		return 0;
	}
	a[0] = a[n+1] = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] > a[i-1] && a[i] > a[i+1]) {
			int tar = max(a[i-1], a[i+1]);
			cnt = (cnt+a[i]-tar)%phi;
			a[i] = tar;
		}
	dfs(1, n);
	cout << (long long)(dp[1][n][0]+dp[1][n][1])%mod*power(2, cnt)%mod << endl;
	return 0;
}
