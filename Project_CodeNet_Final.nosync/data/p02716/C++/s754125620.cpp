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














int N, A[201010];
ll dp[201010][2][4][3];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	rep(i, 0, N + 1) rep(top, 0, 2) rep(two, 0, 3) rep(three, 0, 2) dp[i][top][two][three] = -infl;

	dp[0][0][0][0] = 0;

	dp[1][0][0][0] = A[0];
	dp[2][1][0][0] = A[1];
	dp[3][0][1][0] = A[2];

	rep(i, 0, N) rep(top, 0, 2) rep(two, 0, 3) rep(three, 0, 2) if(-infl < dp[i][top][two][three]) {
		chmax(dp[i + 2][top][two][three], dp[i][top][two][three] + A[i + 1]);
		chmax(dp[i + 3][top][two + 1][three], dp[i][top][two][three] + A[i + 2]);
		chmax(dp[i + 4][top][two][three + 1], dp[i][top][two][three] + A[i + 3]);
	}

	ll ans = -infl;
	rep(i, 1, N + 1) rep(top, 0, 2) rep(two, 0, 3) rep(three, 0, 2) if (-infl < dp[i][top][two][three]) {
		int cnt = 0;
		int tot = i;
		if (top == 0) cnt++, tot--;

		rep(t, 0, two) tot--;
		rep(t, 0, three) tot -= 2;

		cnt += tot / 2;

		if (cnt == N / 2) chmax(ans, dp[i][top][two][three]);
	}
	cout << ans << endl;
}





