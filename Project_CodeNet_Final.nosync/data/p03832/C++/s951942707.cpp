#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD ((long long)1e9 + 7)

//#define TEST

// コンビネーションの計算を行うためのクラス
class Combination {
public:
	ll* inv; // 階乗の逆元を格納
	// コンストラクタ
	Combination(ll n) {
		this->n = n;
		frac = new ll[n + 1];
		inv = new ll[n + 1];
		frac[0] = 1; // 0! = 1
		inv[0] = 1; // 0!の逆元 = 1
		for (int i = 1; i <= n; ++i) {
			frac[i] = frac[i - 1] * i % MOD;
			inv[i] = Inverse(frac[i]);
		}
	}
	// メモリの開放を行う
	void free() {
		delete[] frac, inv;
	}
	// nCkの計算を行う 
	ll C(ll n, ll k) {
		if (k < 0) return 0;
		if (k > n) return 0;
		return frac[n] * inv[k] % MOD * inv[n - k] % MOD;
	}
private:
	ll n;
	ll* frac; // 階乗を格納
	ll Pow(ll a, ll b) { // aのb乗の計算
		if (b == 0) return 1;
		ll temp = Pow(a, b / 2);
		if (b & 1) {
			return temp * temp % MOD * a % MOD;
		}
		return temp * temp % MOD;
	}
	ll Inverse(ll a) { // aの逆元を計算
		return Pow(a, MOD - 2);
	}
};

// a^b%MODを計算
ll modpow(ll a, ll b) {
	if (b == 0) return 1;
	ll t = modpow(a, b / 2);
	if (b & 1)
		return t * t % MOD * a % MOD;
	return t * t % MOD;
}

signed main() {
	// 入力を受け取る
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	// コンビネーションの前計算を行う
	Combination com(1001);

	/*
		  dp[i][j] := i人をa～a+j人のグループに2番目
				の条件を満たすように分ける分け方
		というdpを行う.
	*/
	// dpテーブルの用意
	ll** dp = new ll * [n + 1];
	for (int i = 0; i <= n; ++i)
		dp[i] = new ll[b - a + 1];
	// dpテーブルの初期化を次の通り行う.
	// ・dp[0][0] = 1
	// ・dp[a*i][0] = a*iCa * a*(i-1)Ca * ... * aCa / (i!) (i=c,c+1,...,min(n/a,d))
	// ・dp[その他][0] = 0
	for (int i = 0; i <= n; ++i)
		dp[i][0] = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= n / a; ++i) {
		dp[a * i][0] = dp[a * (i - 1)][0] * com.C((ll)a * i, a)
			% MOD * modpow(i, MOD - 2) % MOD;
	}
	for (int i = 1; i <= min(c - 1, n / a); ++i)
		dp[a * i][0] = 0;
	for (int i = min(n / a, d) + 1; i <= n / a; ++i)
		dp[a * i][0] = 0;
	// dpの遷移を行う.
	// ・dp[i][j] = 
	//		f=0,c～min(i/(a+j),d)について、	
	//		  dp[i-f*(a+j)][j-1]*(i人からのa+j人グループf個の作り方)
	//		の和
	for (int j = 1; j <= b - a; ++j) {
		for (int i = 0; i <= n; ++i) {
			int fmax = min(i / (a + j), d);
			dp[i][j] = dp[i][j - 1]; // f=0のとき
			if (fmax == 0) continue;
			// m[l] = iC(a+j) * i-(a+j)C(a+j) * ... * i-(a+j)*lC(a+j)
			ll* m = new ll[fmax];
			m[0] = com.C(i, (ll)a + j);
			for (int l = 1; l < fmax; ++l)
				m[l] = m[l - 1] 
				* com.C((ll)i - ((ll)a + j) * (ll)l, (ll)a + j) % MOD;
			for (int f = c; f <= fmax; ++f) {
				// i人からのa+j人グループf個の作り方はm[f-1]/(f!)
				ll t = dp[i - (a + j) * f][j - 1] * m[f - 1] % MOD
					* com.inv[f] % MOD;
				dp[i][j] += t;
				dp[i][j] %= MOD;
			}
			delete[] m;
		}
	}

	// dpの確認(TEST時のみ)
#ifdef TEST
	cout << "------------dp------------" << endl;
	for (int i = 0; i <= n; ++i) {
		cout << i << " : ";
		for (int j = 0; j <= b - a; ++j)
			cout << dp[i][j] << " ";
		cout << endl;
	}
#endif

	// 答えはdp[n][b-a].
#ifdef TEST
	cout << "------------ans-----------" << endl;
#endif
	cout << dp[n][b - a] << endl;

	// メモリの開放
	for (int i = 0; i <= n; ++i)
		delete[] dp[i];
	delete[] dp;
	com.free();

	return 0;
}