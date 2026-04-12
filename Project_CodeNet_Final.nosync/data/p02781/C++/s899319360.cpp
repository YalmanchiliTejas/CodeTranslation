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
	string s;
	cin >> s;
	int k;
	cin >> k;
	int n = s.size();
	ll dp[101][2][5];	// digit, smaller, count of 1-9
	rep(i, 101) rep(j, 2) rep(l, 5) dp[i][j][l] = 0;
	dp[0][0][0] = 1;
	rep1(i, n) rep(j, 2) rep(l, 4) {
		int d = s[i - 1] - '0';
		for(int m = 0; m <= (j ? 9 : d); m++) {
			dp[i][j || (m < d)][l + (m > 0)] += dp[i - 1][j][l];
		}
	}
	cout << dp[n][1][k] + dp[n][0][k] << endl;
}
