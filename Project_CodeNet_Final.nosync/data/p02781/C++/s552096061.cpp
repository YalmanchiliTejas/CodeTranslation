#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma warning(disable : 4996)
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
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include<random>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;++i)
#define REPR(i, n) for(int i = n-1;i >= 0;--i)
#define FOR(i, m, n) for(int i = m;i < n;++i)
#define FORR(i, m, n) for(int i = m-1;i >= n;--i)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define pb(a) push_back
#define print(x) cout<<(x)<<'\n'
#define pe(x) cout<<(x)<<" "
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
#define int long long
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7; const int MAX = 200020;
const double pi = acos(-1); const double EPS = 1e-12;
const ll INF = 1e18;

ll dp[110][5][2];
void solve() {
	string S; cin >> S;
	vector<int>X;
	int K; cin >> K;
	int N = S.size();
	REP(i, N) {
		X.push_back(S[i] - '0');
	}
	//print("now");
	dp[0][0][0] = 1;
	REP(i, N) {
		REP(c, K + 1) {
			REP(f, 2) {
				if (f) {
					dp[i + 1][c][1] += dp[i][c][f];
					dp[i + 1][c+1][1] += dp[i][c][f] * 9;
				}
				else {
					REP(num, 10) {
						if (num > X[i])continue;
						if (num == X[i]) {
							if (num == 0)dp[i + 1][c][f] += dp[i][c][f];
							else dp[i + 1][c + 1][f] += dp[i][c][f];
						}
						else if(num<X[i]) {
							if (num == 0)dp[i + 1][c][1] += dp[i][c][f];
							else dp[i + 1][c + 1][1] += dp[i][c][f];
						}
					}
				}
			}
		}
	}
	print(dp[N][K][0] + dp[N][K][1]);
}

signed main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);
	//int q; cin >> q;
	//while (q--)
	solve();
}