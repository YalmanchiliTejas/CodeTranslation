#include<iostream>
#include<cassert>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
using namespace std;
//#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int INF = 1e10;
const long double PI = (acos(-1));

int dp[105][4][2];
// dp[i][num][sml] : i桁目まで 非ゼロがnum個 smlが0ならNと一致　smlが1ならN未満が確定

signed main() {
	string N;
	int K;
	cin >> N >> K;
	dp[0][0][0] = 1;
	int len = N.size();
	rep(i, len)rep(num, 10)rep(sml, 2) {
		int nd = N[i] - '0'; //Nのi桁目の数字
		rep(d, 10) {
			int ni = i + 1, nnum = num, nsml = sml;
			if (d != 0)nnum++; //非ゼロのとき、numは1増える
			if (nnum > K)continue; 
			if (sml == 0) { //Nと一致してるなら
				if (d > nd)continue; //ndは超えてはならない
				if (d < nd)nsml = 1; //nd未満なら、次はN未満が確定
			}
			dp[ni][nnum][nsml] += dp[i][num][sml];
		}
	}
	int ans = dp[len][K][0] + dp[len][K][1];
	cout << ans << endl;
}