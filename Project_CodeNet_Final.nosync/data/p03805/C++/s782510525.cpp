#include <bits/stdc++.h>

using namespace std;

#define INF 2000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;

int n;
int m;
int cnt;
int p[10];
int adj[10][10];

void dfs() {
	int univ = (1 << n) - 1;
	int dp[univ+1][univ+1];
	for (int i = 0; i <= univ; i++) {
		for (int j = 0; j <= univ; j++) {
			dp[i][j] = 0;
		}
	}
	dp[1][0] = 1;

	for (int s = 2; s < univ+1; s++) {
		for (int j = 0; j < n; j++) {
			int s2 = s & (univ ^ (1 << j));
//			cout << "s " << bitset<8>(s) << " s2 " << bitset<8>(s2) << "\n";
			for (int k = 0; k < n; k++) {
				if (((1 << k) & s2) && adj[k][j]) {
//					cout << s << " " << k << " " << dp[s2][k] << "\n";
					dp[s][j] += dp[s2][k];
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		ans += dp[univ][i];
	}
	cout << ans << "\n";;
}

int main()
{
	cin >> n >> m;
	memset(p, 0, sizeof(p));
	cnt = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a][b]=1;
		adj[b][a]=1;
	}
	dfs();
}
