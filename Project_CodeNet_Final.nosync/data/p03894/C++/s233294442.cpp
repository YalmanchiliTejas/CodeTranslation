//#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define IN(a, b, x) (a<=x&&x<b)
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define INF (1LL<<30)
#define LLINF (1LL<<60)
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int a[100010], b[100010];
int dp[2][100010];
bool used[100010];
signed main(void)
{
	int n, q;
	cin >> n >> q;
	REP(i, q) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
	}

	VI v[2];
	int cur = 0, vis = 1;
	dp[0][0] = 1;
	dp[0][1] = 2;
	v[0].PB(0); v[0].PB(1);
	//REP(i, n) cout << dp[cur][i] << " "; cout << endl;
	REP(i, q) {
		memset(used, false, sizeof(used));
		for(int j: v[cur]) {
			//cout << "j:" << j << endl;
			if(used[j]) continue;
			used[j] = true;
			if(a[i] == j) {
				dp[vis][b[i]] = dp[cur][j];
				v[vis].PB(b[i]);
				if(dp[cur][j] == 1) {
					if(b[i] != 0 && dp[vis][b[i]-1] == 0) {
						/*cout << "b-1:" << b[i]-1 << endl;*/ dp[vis][b[i]-1] = 2; v[vis].PB(b[i]-1);
					}
					if(b[i] != n-1 && dp[vis][b[i]+1] == 0) {
						/*cout << "b+1:" << b[i]+1 << endl;*/ dp[vis][b[i]+1] = 2; v[vis].PB(b[i]+1);
					}
				}
			}	else if(b[i] == j) {
				dp[vis][a[i]] = dp[cur][j];
				v[vis].PB(a[i]);
				if(dp[cur][j] == 1) {
					if(a[i] != 0 && dp[vis][a[i]-1] == 0) {
						/*cout<<"a-1:"<<a[i]-1;*/ dp[vis][a[i]-1] = 2; v[vis].PB(a[i]-1);
					}
					if(a[i] != n-1 && dp[vis][a[i]+1] == 0) {
						/*cout<<"a+1:"<<a[i]+1;*/ dp[vis][a[i]+1] = 2; v[vis].PB(a[i]+1);
					}
				}
			} else {
				dp[vis][j] = dp[cur][j];
				v[vis].PB(j);
				if(dp[cur][j] == 1) {
					if(j != 0 && dp[vis][j-1] == 0) {
						/*cout << "j-1:" << j-1 << endl;*/ dp[vis][j-1] = 2; v[vis].PB(j-1);
					}
					if(j != n-1 && dp[vis][j+1] == 0) {
						/*cout << "j+1:" << j+1 << endl;*/ dp[vis][j+1] = 2; v[vis].PB(j+1);
					}
				}
			}
			dp[cur][j] = 0;
		}
		v[cur].erase(ALL(v[cur]));
		//REP(j, n) cout << dp[vis][j] << " "; cout << endl;
		cur ^= 1;
		vis ^= 1;
	}

	ll ret = 0;
	REP(i, n) if(dp[cur][i] != 0) {
		ret++;
		//cout << i << " ";
	}
	cout << ret << endl;

	return 0;
}
