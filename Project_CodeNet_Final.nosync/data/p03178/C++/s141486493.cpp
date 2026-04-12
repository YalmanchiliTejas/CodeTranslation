#include<iostream>
#include<cstdio>
#include<cstring>
#include <fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<bitset>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<iomanip>
#include <functional>
#include <math.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long long int MOD = 1000000007;
const int INF = 1000000007;
const double EPS = 1e-10;
const double PI = 3.14159265359;
const int N = 100005;
//cout << fixed << std::setprecision(9)
//--------------------------

string str;
int d;
ll dp[10005][105][2];

int main() {
	cin >> str;
	cin >> d;
	dp[0][0][0] = 1;

	for (int i = 0; i<str.size(); i++) {
		int pos = str[i] - '0';
		for (int j = 0; j<d; j++) {
			for (int a = 0; a <= pos; a++) {
				if (a == pos) dp[i + 1][(j + a) % d][0] += dp[i][j][0];
				else dp[i + 1][(j + a) % d][1] += dp[i][j][0];
			}
			for (int a = 0; a <= 9; a++) {
				dp[i + 1][(j + a) % d][1] += dp[i][j][1];
			}
		}
		for (int j = 0; j < d; j++)
			for (int k = 0; k < 2; k++)
				dp[i + 1][j][k] %= MOD;
	}
	ll ans = -1LL + dp[str.size()][0][0] + dp[str.size()][0][1];
	cout << (ans%MOD + MOD) % MOD << endl;
}

