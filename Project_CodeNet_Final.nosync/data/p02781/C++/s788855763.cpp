#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
#include <time.h>
#include <chrono>
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,a,b) for(ll i=a;i>b;i--)
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define repl(i,l,r) for(int i=(1);i<(r);i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = 1e9 + 7;
const ll mod = 1e9 + 7;


ll dp[101][2][4];//0,1,2,3


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string S;
	ll K;
	cin >> S >> K;
	
		dp[0][0][0] = 1;
		dp[0][1][0] = 0;

	FOR(i, 1, S.length()+1) {
		int num = int(S[i-1] - '0');
		
		//dp[i-1][1][n] 既に未満フラグが経っているとき、
		FOR(j, 0, 4) {
			if (j > 0)dp[i][1][j] += dp[i - 1][1][j - 1] * 9;
			dp[i][1][j] += dp[i - 1][1][j];
		}
		//未満フラグが経っていないとき
		if (num == 0) {
			//未満フラグを立てないとき
			FOR(j, 0, 4)dp[i][0][j] += dp[i - 1][0][j];
		}
		else {
			//未満フラグたてない
			FOR(j, 1, 4)dp[i][0][j] += dp[i - 1][0][j - 1];
			//未満フラグ立てる
			FOR(j, 1, 4)dp[i][1][j] += dp[i - 1][0][j - 1] * (num-1);
			FOR(j, 0, 4)dp[i][1][j] += dp[i - 1][0][j];
		}


	}
	cout << dp[S.length()][0][K] + dp[S.length()][1][K] << endl;
	






	return 0;
}
