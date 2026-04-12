//人数が少ないグループから作る。グループに人を入れるときは、番号が小さい人から入れる。
//↑の2つを守れば、重複なく列挙可能。あとは、愚直なDPをするだけで解けそうな雰囲気。
#include <iostream>
#define int long long
using namespace std;

int powmod(int a, int n, int mod) {
	if (n == 0) return 1;
	if (n & 1) return (a * powmod(a, n - 1, mod)) % mod;
	return powmod((a * a) % mod, n / 2, mod);
}

int mod = 1000000007;
int n, a, b, c, d;
int fact[1001];
int factInv[1001];
int dp[1001][1001];

//残りn人いて、今からm人グループを作る。
int dfs(int n, int m) {
	if (m == b + 1) { return (n == 0); }
	if (dp[n][m] != -1) return dp[n][m];
	
	int ret = dfs(n, m + 1);
	for (int x = c; x <= d && m * x <= n; x++) {
		int cnt = fact[n] * factInv[n - m * x] % mod * powmod(factInv[m], x, mod) % mod * factInv[x] % mod;
		ret += cnt * dfs(n - m * x, m + 1);
		ret %= mod;
	}
	return dp[n][m] = ret;
}

signed main() {
	int i, j;
	
	cin >> n >> a >> b >> c >> d;
	fact[0] = 1;
	for (i = 1; i <= n; i++) fact[i] = (i * fact[i - 1]) % mod;
	for (i = 0; i <= n; i++) factInv[i] = powmod(fact[i], mod - 2, mod);
	for (i = 0; i <= n; i++) for (j = 0; j <= n; j++) dp[i][j] = -1;
	
	cout << dfs(n, a) << endl;
	return 0;
}