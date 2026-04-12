#include "bits/stdc++.h"
#include<random>
using namespace std;
typedef long long int lint;
typedef pair<lint, lint> plint;
typedef pair<double long, double long> pld;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(lint i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(lint i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
const lint MOD = 1e9 + 7, INF = 1e18;

lint dp[3001][3001], N, arr[3000];
bool flag[3001][3001];

lint dfs(lint l, lint r) {
	if (flag[l][r]) return dp[l][r];
	flag[l][r] = true;
	if (l == r) return dp[l][r] = arr[l];
	return dp[l][r] = max(arr[l] - dfs(l + 1, r), arr[r] - dfs(l, r - 1));
}

int main() {
	cin >> N;
	REP(i, N) {
		cin >> arr[i];
	}
	REP(i, N + 1) REP(j, N + 1) flag[i][j] = false;
	cout << dfs(0, N - 1) << endl;
}
