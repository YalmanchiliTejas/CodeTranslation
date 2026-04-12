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

ll dp[10010][2][100];
const int mod = 1000000007;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string K;
	int D;
	cin >> K >> D;
	int N = K.size();
	dp[0][0][0] = 1;
	REP(i, N)REP(smaller, 2)REP(j, D) {
		REP(x, smaller ? 10 : K[i] - '0' + 1) {
			dp[i + 1][smaller || x < (K[i] - '0')][(j + x) % D] += dp[i][smaller][j];
			dp[i + 1][smaller || x < (K[i] - '0')][(j + x) % D] %= mod;
		}
	}

	cout << (dp[N][0][0] + dp[N][1][0] - 1 + mod) % mod << endl;

	return 0;
}
