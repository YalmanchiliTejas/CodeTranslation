//https://onlinejudge.u-aizu.ac.jp/beta/room.html#KUPC2020Spring/problems/K
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














int N; string S; int P[1 << 19];
int dp[19][1 << 19];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> S;
	rep(i, 0, 1 << N) cin >> P[i];
	rep(i, 0, 1 << N) P[(1 << N) + i] = P[i];

	rep(i, 0, 1 << (N + 1)) dp[0][i] = P[i];
	rep(p, 1, N + 1) rep(L, 0, 1 << (N + 1)) {
		int R = L + (1 << (p - 1));
		if (1 << (N + 1) <= R) continue;
		int x = dp[p - 1][L];
		int y = dp[p - 1][R];
		tie(x, y) = make_pair( min(x, y), max(x, y) );

		if (S[y - x - 1] == '0') dp[p][L] = x;
		else dp[p][L] = y;
	}

	rep(i, 0, 1 << N) printf("%d\n", dp[N][i]);
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
//　
