#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1LL << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int dp[105][4][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int K;
	cin >> s >> K;
	int n = s.size();
	dp[0][0][0] = 1;
	rep(i, n)rep(j, 4)rep(k, 2) {
		int d = s[i] - '0';
		rep(a, 10) {
			int ni = i + 1, nj = j, nk = k;
			if (a != 0) nj++;
			if (nj > K) continue;
			if (nk == 0) {
				if (d > a) nk = 1;
				if (d < a) continue;
			}
			dp[ni][nj][nk] += dp[i][j][k];
		}
	}
	cout << dp[n][K][0] + dp[n][K][1] << endl;
	return 0;
}