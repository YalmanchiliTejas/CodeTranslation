#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPR(i,n) for(int i=(n)-1;i>=0;i--)
#define ALL(s) (s).begin(), (s).end()
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase( unique(ALL(v)) , v.end());
#define PAU system("pause")

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = (1 << 28);
const ll LINF = 1e18;
const double PI = acos(-1);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string K;
	int D;
	cin >> K >> D;
	vector<vvll> dp(SZ(K) + 1, vvll(D, vll(2, 0)));
	dp[0][0][1] = 1;
	REP(i, SZ(K)) {
		int r = K[i] - '0';
		REP(next, 10) {
			REP(j, D) {
				if (r == next) {
					dp[i + 1][(next + j) % D][1] += dp[i][j][1];
					dp[i + 1][(next + j) % D][0] += dp[i][j][0];
				}
				else if(r > next){
					dp[i + 1][(next + j) % D][0] += dp[i][j][0] + dp[i][j][1];
				}
				else {
					dp[i + 1][(next + j) % D][0] += dp[i][j][0];
				}
				dp[i + 1][(next + j) % D][0] %= MOD;
				dp[i + 1][(next + j) % D][1] %= MOD;
			}
		}
	}
	cout << (dp[SZ(K)][0][0] + dp[SZ(K)][0][1] - 1 + MOD) % MOD << endl;
	PAU;
	return 0;
}
