#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<unordered_map>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string N;
	int K;


	cin >> N >> K;
	long long dp[102][4][2] = {};
	dp[0][0][0] = 1;

	rep(i, N.size()) rep(j, K) rep(k, 2) {
		dp[i + 1][j][k || 0 < N[i] - '0'] += dp[i][j][k];
		for(int d=1;d<10;d++){
			if (k == 0 && d >N[i] - '0')break;

			dp[i + 1][j + 1][k || d < N[i] - '0'] += dp[i][j][k];
		}
	}
	long long ans = 0;
	rep(i, N.size() + 1) rep(k, 2) {
		ans += dp[i][K][k];
	}
	cout << ans << endl;




	return 0;
}