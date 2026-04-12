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

	int dp[3010][3010];

	FOR(i, 0, N) {
		REP(L, N) {
			int R = L + i;
			if (L == R) {
				if ((N - (R - L + 1)) % 2 == 0) {
					dp[L][R] = A[L];
				}
				else dp[L][R] = -A[L];
				continue;
			}
			if (N - (R - L + 1) < 0)continue;
			if (R > N)continue;

			if ((N - (R - L + 1)) % 2 == 0) {//先手の手番＿最大化しようとする

				dp[L][R] = max(dp[L + 1][R] + A[L], dp[L][R - 1] + A[R]);
			}
			else {
				dp[L][R] = min(dp[L + 1][R] - A[L], dp[L][R - 1] - A[R]);
			}
		}
	}

	cout << dp[0][N - 1] << endl;

	//REP(i, N)FOR(j, i, N)cout << i << " " << j << " " << dp[i][j] << endl;

	return 0;
}

