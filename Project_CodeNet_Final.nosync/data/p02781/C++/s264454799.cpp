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


int dp[110][4][2];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	int N, K;
	cin >> S >> K;
	N = S.size();

	dp[0][0][0] = 1;

	REP(i, N) {
		REP(j, 4) {
			REP(k, 2) {

				int nd = S[i] - '0';
				REP(d, 10) {
					int ni = i + 1, nj = j, nk = k;

					if (d != 0)nj++;
					if (nj > K)continue;
					if (k == 0) {
						if (d > nd)continue;
						if (d < nd)nk = 1;
					}

					dp[ni][nj][nk] += dp[i][j][k];
				}

			}
		}
	}
	
	cout << dp[N][K][0] + dp[N][K][1] << endl;



	return 0;
}

