#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define REP(n) for(int i = 0; i < n; i++)
#define all(p) p.begin(), p.end()
#define count_1(p) __builtin_popcountll(p)
#define count_0(p) __builtin_ctzll(p)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
template<class X=int>inline X min(X a,X b,X c){return min(min(a,b),c);}
template<class X=int>inline X min(X a,X b,X c,X d){return min(min(a,b,c),d);}
template<class X=int> inline X max(X a,X b,X c){return max(max(a,b),c);}
template<class X=int> inline X max(X a,X b,X c,X d){return max(max(a,b,c),d);}
template<class X=int> inline X mid(X s,X e){return (s+(e-s)/2);}
template<class X=int> inline X len(X s,X e){return (e-s+1);}
const int MOD = 1e9 + 7;
const int INF = 987654321;
const bool TESTCASES = 0;
const bool CODEJAM = 0;

void solve() {
	int n;
	cin >> n;
	vector<int> A(n);
	vll pre(n + 1);
	vvll dp(n, vll(n));
	REP(n) {
		cin >> A[i];
		pre[i + 1] = pre[i] + A[i], dp[i][i] = A[i];
	}
	for(int p = 1; p < n; p++) {
		for(int i = 0; i < n - p; i++) {
			int j = i + p;
			dp[i][j] = max(A[i] + pre[j + 1] - pre[i + 1] - dp[i + 1][j],
					A[j] + pre[j] - pre[i] - dp[i][j - 1]);
		}
	}
	cout << 2*dp[0][n - 1] - pre[n] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T = 1;
	if(TESTCASES) cin >> T;
	for(int t = 1; t <= T; t++) {
		if(CODEJAM) cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}
