#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef vector<pii> VP;
typedef vector<string> VS;
typedef priority_queue<int> PQ;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 998244353
//priority_queue<int,vector<int>, greater<int> > q2;



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, S; cin >> N >> S;
	VI A(N);
	REP(i, N)cin >> A[i];
	int dp[3010][3010][3] = { 0 };

	dp[0][0][0] = 1;

	eFOR(i, 1, N) {

		eFOR(j, 0, S) {

			dp[i][j][0] += dp[i - 1][j][0];
			dp[i][j][1] += dp[i - 1][j][0] + dp[i - 1][j][1];
			dp[i][j][2] += dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2];
			
			dp[i][j][0] %= mod;
			dp[i][j][1] %= mod;
			dp[i][j][2] %= mod;

			if (j - A[i - 1] < 0)continue;

			dp[i][j][1] += dp[i - 1][j - A[i - 1]][0] + dp[i - 1][j - A[i - 1]][1];
			dp[i][j][2] += dp[i - 1][j - A[i - 1]][0] + dp[i - 1][j - A[i - 1]][1];

			dp[i][j][0] %= mod;
			dp[i][j][1] %= mod;
			dp[i][j][2] %= mod;


			//cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << " " << dp[i][j][2] << endl;
		}
	}

	cout << dp[N][S][2] << endl;

	return 0;
}

