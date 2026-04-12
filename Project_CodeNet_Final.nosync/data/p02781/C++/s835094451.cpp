#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0, -1, 1, 0 };
const ll dy[4] = { -1, 0, 0, 1 };
const int INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
using Graph = vector<vector<int>>;
///////////////////////////////////////




int main() {
	string N; cin >> N;
	int n = N.size();
	int K; cin >> K;
	ll dp[110][2][4];
	//dp[i][j][k][l]で、上位i個の桁を決めた,N未満が確定している,一番上の桁が0以外で確定,0以外の数字がk個
	REP(i, 110) {
		REP(j, 2) {
			REP(k, 4) {
				dp[i][j][k] = 0;
			}
		}
	}
	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k <= K; ++k) {
				int x;
				x = j ? 9 : N[i] - '0';
				for (int d = 0; d <= x; ++d) {
					if (d != 0) {
						if (k < K) {
							dp[i + 1][j || (d < x)][k + 1] += dp[i][j][k];
						}
					}
					else {
						dp[i + 1][j||(d<x)][k] += dp[i][j][k];
					}
				}
			}
		}
	}
	cout << dp[n][0][K] + dp[n][1][K] << endl;
	return 0;
}