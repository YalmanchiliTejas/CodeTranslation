#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0, -1, 1, 0 };
const ll dy[4] = { -1, 0, 0, 1 };
const int INF = 1e9 + 7;
const ll inf = 1LL << 50;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
///////////////////////////////////////

//明らかにxとyについて独立なのでxの差の絶対値の和とyの差の絶対値の和をそれぞれ求める
//Xの差について考える。ある2マスの組み合わせを固定した時これら以外からk-2マス選ぶ場合に
//全てに1度ずつこれらの差が寄与するのでこの組を固定して考えると(N*M-2)C(k-2)通りある
//さらにXが同じ場合は差が0なのでxが異なると仮定するとXの差の絶対値がdとなるように
//2マス選ぶ方法は(N-d)*M^2通りある。これを全てのdに対して足し合わせるとXについての答えが
//求まる。yについてもnとmを入れ替えると同様に解くことができる。

//差のほうを固定するという考え方！

//あるマス2つにコマが置いてあるようなコマの配置の通り数を計算する。
//その２マスがどこであっても残りのマスA-2個に残りのコマk-2個を置く場合の数になるこれをxとする
//求める値はマス2つのペア全通りについてそのマンハッタン距離を合計して最後にxを掛けたもの
//マス二つのペア全通りについてマンハッタン距離(の縦だけ)を合計した値は

vector<pair<ll, ll>>prime_factorize(ll n) {
	vector<pair<ll, ll>>res;
	for (ll p = 2; p*p <= n; ++p) {
		if (n%p != 0)continue;
		int num = 0;
		while (n%p == 0) { ++num; n /= p; }
		res.push_back(make_pair(p, num));
	}
	if (n != 1)res.push_back(make_pair(n, 1));
	return res;
}
const int MAX = 210000;
ll fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; ++i) {
		fac[i] = fac[i - 1] * i%INF;
		inv[i] = INF - inv[INF%i] * (INF / i) % INF;
		finv[i] = finv[i - 1] * inv[i] % INF;
	}
}
ll COM(int n, int k) {
	if (n < k)return 0;
	if (n < 0 || k < 0)return 0;
	return fac[n] * (finv[k] * finv[n - k] % INF) % INF;
}//二項係数ライブラリ
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	COMinit();
	ll ans = 0;
	for (ll d = 1; d <= N - 1; ++d) {
		ans += d * (N - d)*M*M;
		ans %= INF;
	}
	for (ll d = 1; d <= M - 1; ++d) {
		ans += d * (M - d)*N*N;
		ans %= INF;
	}
	ans *= COM(N*M - 2, K-2);
	ans %= INF;
	cout << ans << endl;
	return 0;
}