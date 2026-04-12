#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define all(obj) (obj).begin(), (obj).end()
const ll INF = 1e10;
void chmax(ll &a, ll b) { a = max(a, b); }
void chmin(ll &a, ll b) { a = min(a, b); }

ll aN[3000];
// メモ[手番][左端位置][右端位置] = この局面からの結果
ll memo[2][3010][3010];
bool visited[2][3010][3010];

ll rec(int turn, int l, int r) {
	// 全部取り切ったので終了
	if (l > r) return 0;
	// 既に見た局面ならメモの内容を返す
	if (visited[turn][l][r]) return memo[turn][l][r];
	// 先手番
	if (turn == 0) {
		ll mx = -INF;
		mx = max(rec(1, l+1, r) + aN[l], rec(1, l, r-1) + aN[r]);
		// 訪問済にする
		visited[turn][l][r] = 1;
		// ここより深い所を探し終わったので結果をメモする
		return memo[turn][l][r] = mx;
	// 後手番
	} else {
		ll mn = INF;
		mn = min(rec(0, l+1, r) - aN[l], rec(0, l, r-1) - aN[r]);
		visited[turn][l][r] = 1;
		return memo[turn][l][r] = mn;
	}
}

int main() {
	int N;
	cin >> N;
	rep(i, 0, N) cin >> aN[i];
	cout << rec(0, 0, N-1) << endl;
	return 0;
}
