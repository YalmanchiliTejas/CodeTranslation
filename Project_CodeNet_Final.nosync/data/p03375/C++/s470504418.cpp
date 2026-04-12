//初手包除。O(N^3)から計算量を落とせる気配がないように見えるが、実はループの順番（変数を固定する順番）を変えると上手くいくことがある。
//具体的には、↓の問題の答えをg(k, M)としたとき、g(1, 1)～g(N, N)をすべて求めるのにO(N^2)しかかからず、全体計算量もO(N^2)になる。
//・トッピング1～kのどれかは入っているラーメンをM個取ります。トッピング1～kを1個以下にしたいです。他の具は0個にしたいです。ラーメンの取り方はいくつありますか？
//余談：数え上げでmodを取るのは、答えの大きさが計算量に依存しないようにすることで、計算量の見積もりをしやすくするためだと思われます。
//余談：答えが大きいのに計算量を削減する必要があるのか？についてですが、計算量を削減する過程で数学的に面白い性質が発見できたりするので、割と重要だと思っています。
//余談：重要というのは、あくまでもプログラミングを使った数学を楽しむときに重要という話なので、実用として重要かどうかはあまり考えていません。

#include <iostream>
#define int long long
using namespace std;

int powmod(int a, int n, int mod) {
	if (n == 0) return 1;
	if (n & 1) return (a * powmod(a, n - 1, mod)) % mod;
	return powmod((a * a) % mod, n / 2, mod);
}

int p2[9000001], p22[3001], fact[3001], factInv[3001], comb[3001][3001];
int dpG[3001][3001];

void init(int n, int mod) {
	int i, j;
	
	p2[0] = 1; for (i = 1; i <= n * n; i++) p2[i] = (p2[i - 1] * 2) % mod;
	p22[0] = 2; for (i = 1; i <= n; i++) p22[i] = (p22[i - 1] * p22[i - 1]) % mod;
	fact[0] = 1; for (i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;
	for (i = 0; i <= n; i++) factInv[i] = powmod(fact[i], mod - 2, mod);
	for (i = 0; i <= n; i++) comb[i][0] = 1;
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
	for (i = 0; i <= n; i++) for (j = 0; j <= n; j++) dpG[i][j] = -1;
}

int n, mod;

//トッピング1～kのどれかは入っているラーメンをm個取ります。
//トッピング1～kを1個以下にしたいです。他の具は0個にしたいです。
//ラーメンの取り方はいくつありますか？(取る順番も考えるとする)
int g(int k, int m) {
	if (m > k) return 0;
	if (m == 0) return 1;
	if (dpG[k][m] != -1) return dpG[k][m];
	return dpG[k][m] = (m * g(k - 1, m - 1) + (m + 1) * g(k - 1, m)) % mod;
}

//トッピング1～kは1個以下, それ以外の具は任意個とするとき、ラーメンの選び方は何通りあるか？(0≦k≦n)
int f(int k) {
	if (k == 0) return p22[n];
	
	int ret = 0;
	for (int m = 1; m <= k; m++) {
		ret += g(k, m) * factInv[m] % mod * p2[(n - k) * m] % mod;
		ret %= mod;
	}
	ret *= p22[n - k];
	ret += p22[n - k];
	ret %= mod;
	return ret;
}

signed main(){
	cin >> n >> mod;
	init(n, mod);
	
	int ans = 0;
	for (int k = 0; k <= n; k++) {
		int res = comb[n][k] * f(k);
		res %= mod;
		if (k & 1) res = (mod - res) % mod;
		ans += res;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}