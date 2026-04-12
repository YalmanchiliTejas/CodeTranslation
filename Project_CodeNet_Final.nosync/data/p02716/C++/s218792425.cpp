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
#define mod 1000000007
//priority_queue<int,vector<int>, greater<int> > q2;



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	VI A(N);
	REP(i, N)cin >> A[i];

	vector<VI> dp(N + 1, VI(3, 0));

	eFOR(i, 1, N) {

		if (i % 2) {
			if (i != 1)dp[i][2] = max(dp[i - 1][1], dp[i - 2][2]) + A[i - 1];
			else dp[i][2] = max(dp[i - 1][1], 0LL) + A[i - 1];

			if (i != 1)dp[i][1] = max(dp[i - 1][0] + A[i - 1], dp[i - 2][0] + A[i - 1]);
			else dp[i][1] = max(dp[i - 1][0] + A[i - 1], A[i - 1]);

			dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
		}
		else {
			if (i != 1)dp[i][2] = max(dp[i - 1][0], dp[i - 2][1]) + A[i - 1];
			else dp[i][2] = max(dp[i - 1][0], A[i - 1]);

			dp[i][1] = dp[i - 1][2];
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		}

	}




	if (N % 2)cout << max(dp[N][0],dp[N][1]) << endl;
	else cout << max(dp[N][2], dp[N][1]) << endl;



	return 0;
}

