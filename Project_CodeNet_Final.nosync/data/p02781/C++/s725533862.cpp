#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
int ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.second < secondElof.second;
}
ll nod(ll F) { return log10(F) + 1; }
//**定義場所**//
//gcd, isPrime, eratos, modinv, bitSearch, dfs, bfs, dijkstra, UnionFind, COM//
ll i, j, k, l, m, n; ll N, M, K, H, W, L; string S;
ll MOD = 1000000007; ll ans = 0; ll INF = 9999999999999;
vl flag, color; vll path;
//***********//
int main() {
	string S;
	cin >> S;
	cin >> K;
	N = S.length();
	vl A(N);
	for (i = 0; i < N; i++) {
		A[i] = ctoi(S[i]);
	}
	// dp[i][smaller][j]
	// 今調べている桁をi, 未満フラグをsmaller, 0が出た回数をjとする
	vector<vll> dp(N+1, vll(2, vl(K+1, 0)));
	// 0桁目は便宜上0であると考える
	// 0桁目は0しかありえないがこれはsmallerが確定していないのでsmaller=0しかありえない
	// 結局dp[0][0][0]=1, それ以外は全て0で初期化すればよい
	for (i = 0; i < N + 1; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < K + 1; k++) {
				dp[i][j][k] = 0;
			}
		}
	}
	dp[0][0][0] = 1;
	for (i = 0; i < N; i++) {
		for (ll smaller = 0; smaller < 2; smaller++) {
			for (j = 0; j < K + 1; j++) {
				for (ll x = 0; x <= (smaller ? 9 : A[i]); x++) {
					// j==K で x>0 の時はサイズオーバーで死ぬのでcontinue処理！
					if (j == K && x > 0) { continue; }
					dp[i + 1][smaller || x < A[i]][j + (x > 0)] += dp[i][smaller][j];
				}
			}
		}
	}
	// [smaller || x < A[i]]は以下の寄与条件を反映させたものである。
	// smaller=0 から smaller=0 → x = A[i] のとき寄与
	// smaller=0 から smaller=1 → x < A[i] のとき寄与
	// smaller = 1 から smaller = 0 → 常に寄与なし
	// smaller=1 から smaller=1 → 常に寄与
	// [j + (x > 0)]は以下の寄与条件を反映させたものである。(但しj==Kのときのみ例外処理アリ)
	// j=p から j=p → x=0のとき寄与
	// j=p から j=p+1 → x!=0のとき寄与
	cout << dp[N][0][K] + dp[N][1][K];
}
