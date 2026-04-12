#include<iostream>
#include<iomanip>
#include<climits>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<string>
#include<cmath>
#include<complex>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll dp[105][2][4];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	int K;
	cin >> S >> K;
	int N = S.size();
	dp[0][0][0] = 1;
	REP(i, N) {
		dp[i + 1][0][0] = dp[i][0][0] * (S[i] == '0');
		dp[i + 1][1][0] = dp[i][0][0] * (S[i] > '0') + dp[i][1][0];
		REP(j, K) {
			dp[i + 1][0][j + 1] = dp[i][0][j] * (S[i] > '0') + dp[i][0][j + 1] * (S[i] == '0');
			dp[i + 1][1][j + 1] = dp[i][0][j] * (max(0, S[i] - '1')) + dp[i][0][j + 1] * (S[i] > '0')
				+ dp[i][1][j] * 9 + dp[i][1][j + 1];
		}
	}

	cout << dp[N][0][K] + dp[N][1][K] << endl;

	return 0;
}
