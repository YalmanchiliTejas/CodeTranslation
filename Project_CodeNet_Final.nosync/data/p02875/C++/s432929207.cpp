//＊最初に、入力のNを1/2倍しておく。以降では1≦N≦5*10^6として考える。
//AB, BA -> AA, BBと置き換えて良い. （偶数番目のAをBに, BをAにした文字列Tを考えると分かる）
//置き換え後、A,BだけならAB,BAを消せるので、AとBが同数が必要条件。
//逆にAとBが同数(1個以上)なら, AB, BAがどこかに存在するので、帰納的に十分性が成立。
//Cは(AまたはB)として使えるので、長さ2NのABC列であって「A,BがN個以下」を数えれば良い。
//否定を取ると「AがN+1個以上」または「BがN+1個以上」となりこれは排反かつ対称な条件なので嬉しい。
//「AがN+1個以上」はAの個数を全探索すれば容易に計算可能。
//1～Nのmod P (P=998244353)での逆元の計算にO(NlogP)かけると厳しいが、これはO(N)にできるので大丈夫。

#include <iostream>
#define int long long
using namespace std;

const int MAX = 10000010;
const int mod = 998244353;
int fact[MAX], finv[MAX], inv[MAX];
int pow2[MAX];

int comb(int n, int k) {
	if (k > n) return 0;
	return fact[n] * finv[k] % mod * finv[n - k] % mod;
}

int n;

signed main() {
	int i;
	
	cin >> n;
	n /= 2;
	
	//参考：http://drken1215.hatenablog.com/entry/2018/06/08/210000
	fact[0] = fact[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (i = 2; i < MAX; i++) {
		fact[i] = fact[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
	
	pow2[0] = 1;
	for (i = 1; i < MAX; i++) {
		pow2[i] = pow2[i - 1] * 2 % mod;
	}
	
	int ngCnt = 0;
	for (i = n + 1; i <= 2 * n; i++) {
		ngCnt += comb(2 * n, i) * pow2[2 * n - i] % mod;
		ngCnt %= mod;
	}
	
	int all = 1;
	for (i = 0; i < 2 * n; i++) (all *= 3) %= mod;
	
	int ans = (all - 2 * ngCnt + 2 * mod) % mod;
	cout << ans << endl;
	return 0;
}