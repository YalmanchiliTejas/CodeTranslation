#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please


int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N;
	scanf("%d", &N);

	ll dp[2][3];
	dp[0][0] = 0;
	dp[0][1] = -1e18;
	dp[0][2] = -1e18;
	dp[1][0] = -1e18;
	dp[1][1] = -1e18;
	dp[1][2] = -1e18;
	int x = 0;
	int y = 1;

	rep(i, N) {
		int a;
		scanf("%d", &a);

		chmax(dp[y][1], dp[x][0]);
		dp[x][0] = dp[x][0] + a;
		chmax(dp[y][2], dp[x][1]);
		dp[x][1] = dp[x][1] + a;
		dp[x][2] = dp[x][2] + a;

		swap(x, y);
	}

	if (N % 2) {
		printf("%lld\n", max(dp[y][2], dp[x][1]));
	}
	else {
		printf("%lld\n", max(dp[y][1], dp[x][0]));
	}

	Would you please return 0;
}