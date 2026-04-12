#include <iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<unordered_map>

using namespace std;

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep(i,j,n) for(ll (i)=(j);(i)<(n);(i)++)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
#define F first
#define S second
#define en "\n"
typedef pair<ll, ll> P;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;
typedef vector<ll> Array;
typedef vector<Array> Matrix;
const int loose = 0;
const int tight = 1;



template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

//グラフ関連
struct Edge {//グラフ
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

ll digit_DP(string s,ll k) {
	ll n = s.size();
	vector<Matrix> dp(k+1, Matrix(n + 1, Array(2, 0)));
	dp[0][0][tight] = 1;
	REP(i, n) {
		ll d = s[i] - '0';
		ll ni = i + 1;
		REP(t, 2) {
			REP(kk, k+1) {
				rep(j, 0, 10) {
					if (t == tight && d < j) break;
					ll nt = ((t == tight) && (j == d)) ? tight : loose;
					if (j == 0) {
						dp[kk][ni][nt] += dp[kk][i][t];
					}
					else {
						if (kk + 1 <= k) dp[kk+1][ni][nt] += dp[kk][i][t];
					}
				}
			}
		}
	}

	return  dp[k][n][loose] + dp[k][n][tight];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;
	ll k;
	cin >> k;
	cout << digit_DP(s, k) << endl;

	return 0;
}
