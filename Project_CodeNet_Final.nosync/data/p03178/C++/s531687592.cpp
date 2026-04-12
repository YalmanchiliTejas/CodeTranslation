#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include <fstream>
#include <time.h>
#include <iterator>



#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()
#define unko signed
using namespace std;
int MOD = (ll)1000000000 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;
const int MAX = 500050;

int dp[10010][2][100];
//dp[i][isless][r]
unko main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	string K;
	int D;
	cin >> K >> D;
	int N = K.size();
	//dp[0][1][0] = 1;
	dp[0][0][0] = 1;
	REP(i, N) {//i+1桁目について
		int pos = K[i] - '0';
			REP(j, 10) {//i+1桁目の数字
				REP(r, D) {
					if (j == pos) {
						dp[i + 1][0][(r + j) % D] += dp[i][0][r];
						dp[i + 1][1][(r + j) % D] += dp[i][1][r];
					}
					else if (j < pos) {
						dp[i + 1][1][(r + j) % D] += dp[i][0][r] + dp[i][1][r];
					}
					else {
						dp[i + 1][1][(r + j) % D] += dp[i][1][r];
					}
					dp[i + 1][0][(r + j) % D] %= MOD;
					dp[i + 1][1][(r + j) % D] %= MOD;
				}
			}
	}
	int ans = (dp[N][0][0] + dp[N][1][0]-1+MOD) % MOD;//この答えには「0」の分も含まれてるので1引いておく
	print(ans);
}
