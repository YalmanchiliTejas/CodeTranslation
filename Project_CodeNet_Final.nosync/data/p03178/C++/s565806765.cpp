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
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int D, N;
	string S;
	cin >> S >> D;

	int dp[10010][110][2] = { 0 };

	N = S.size();

	dp[0][0][0] = 1;

	REP(i, N) {

		int a = S[i] - '0';

		REP(j, D) {
			REP(k, 10) {
				int nd = (k + j) % D;

				if (k < a) {
					dp[i + 1][nd][1] += dp[i][j][1] + dp[i][j][0];
					dp[i + 1][nd][1] %= mod;
				}
				else if (k > a) {
					dp[i + 1][nd][1] += dp[i][j][1];
					dp[i + 1][nd][1] %= mod;
				}
				else {
					dp[i + 1][nd][1] += dp[i][j][1];
					dp[i + 1][nd][0] += dp[i][j][0];
					dp[i + 1][nd][1] %= mod;
					dp[i + 1][nd][0] %= mod;
				}
			}
		}
	}


	cout << (dp[N][0][0] + dp[N][0][1] + mod - 1) % mod << endl;

	return 0;
}

