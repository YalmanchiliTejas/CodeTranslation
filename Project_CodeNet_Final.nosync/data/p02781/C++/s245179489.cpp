#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
#include <iomanip>
#include <math.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60
const double PI = 3.14159265358979323846;

ll dp[109][4][2]; // 桁、未満フラグ、0の個数
int a[109];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S; cin >> S;
	int K; cin >> K;
	int N = S.size();
	for (int i = 0; i < S.size(); i++) a[i] = S[i] - '0';

	dp[0][1][1] = a[0] - 1;
	dp[0][1][0] = 1;
	dp[0][0][1] = 1;
	dp[0][0][0] = 0;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][j][1] = dp[i - 1][j][1];
			if (j > 0)dp[i][j][1] += dp[i - 1][j - 1][1] * 9;
			if (a[i] > 0) {
				dp[i][j][1] += dp[i - 1][j][0];
				if (j > 0) dp[i][j][1] += dp[i - 1][j - 1][0] * (a[i] - 1);
			}

			if (a[i] > 0) { if (j > 0) dp[i][j][0] = dp[i - 1][j - 1][0]; }
			else dp[i][j][0] = dp[i - 1][j][0];
		}
	}
	cout << dp[N - 1][K][1] + dp[N - 1][K][0] << endl;

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			cout << "("<<dp[i][j][1] << ","<< dp[i][j][0]<<")" << " ";
		}
		cout << endl;
	}
	*/

	return 0;
}