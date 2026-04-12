#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

int main() {
	string n;
	cin >> n;
	int k;
	cin >> k;
	ll dp[101][2][4];
	rep(i, 101) rep(j, 2) rep(l, 4) dp[i][j][l] = 0;
	dp[0][0][0] = 1;
	for(int i = 1; i <= n.size(); i++) {
		int d = n[i - 1] - '0';
		// no smaller to no smaller
		dp[i][0][0] = 0;
		for(int l = 1; l <= 3; l++)  dp[i][0][l] = dp[i - 1][0][l - (d > 0)];
		// no smaller to smaller
		if(d > 0) {
			for(int l = 0; l < 4; l++) {
				dp[i][1][l] += dp[i - 1][0][l];
				if(l >= 1) dp[i][1][l] += dp[i - 1][0][l - 1] * (d - 1);
			}
		}
		// smaller to smaller
		for(int l = 0; l < 4; l++) {
			dp[i][1][l] += dp[i - 1][1][l];
			if(l >= 1) dp[i][1][l] += dp[i - 1][1][l - 1] * 9;
		}
	}
	cout << dp[n.size()][0][k] + dp[n.size()][1][k] << endl;
}				
