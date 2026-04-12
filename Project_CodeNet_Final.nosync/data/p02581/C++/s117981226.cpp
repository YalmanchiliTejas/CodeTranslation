#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, A[6010];
int dp[2010][2010];
using tiii = tuple<int, int, int>;
int ma_row[2020];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N * 3) cin >> A[i];

	rep(i, 1, N + 1) rep(j, 1, N + 1) dp[i][j] = -inf;
	dp[A[0]][A[1]] = dp[A[1]][A[0]] = 0;
	rep(i, 1, N + 1) ma_row[i] = -inf;
	ma_row[A[0]] = ma_row[A[1]] = 0;

	int additionalPoint = 0;
	int ma = 0;

	rep(i, 0, N - 1) {
		int idx = i * 3 + 2;

		vector<int> nxt;
		rep(j, 0, 3) nxt.push_back(A[idx + j]);
		sort(all(nxt));

		if (nxt[0] == nxt[1] && nxt[1] == nxt[2]) {
			additionalPoint++;
			continue;
		}

		vector<tiii> changeQueue;
		rep(_a, 0, 3) rep(_b, 0, 3) if(_a != _b) {
			int a = nxt[_a], b = nxt[_b], c = (nxt[0] + nxt[1] + nxt[2] - a - b);

			// dp[i][x][y] -> dp[i + 1][x][a]
			rep(x, 1, N + 1) {
				int opt = -inf;
				//rep(y, 1, N + 1) chmax(opt, dp[x][y]);
				opt = ma_row[x];
				if (b == c) chmax(opt, dp[x][b] + 1);
				changeQueue.push_back(tiii(x, a, opt));
			}

			// dp[i][any][any] -> dp[i + 1][a][b]
			int ma2 = ma;
			chmax(ma2, dp[c][c] + 1);
			changeQueue.push_back(tiii(a, b, ma2));
		}

		fore(t, changeQueue) {
			int x, y, val;
			tie(x, y, val) = t;

			chmax(dp[x][y], val);
			chmax(dp[y][x], val);
			chmax(ma_row[x], val);
			chmax(ma_row[y], val);
			chmax(ma, val);
		}
	}

	int ans = 0;
	rep(x, 1, N + 1) rep(y, 1, N + 1) chmax(ans, dp[x][y] + ((x == y && x == A[N * 3 - 1]) ? 1 : 0));
	ans += additionalPoint;
	cout << ans << endl;
}





