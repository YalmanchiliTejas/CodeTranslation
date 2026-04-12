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


#define MOD 998244353

int N, S;
int A[3000];

int dp[3001][3001];



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	rep(i, N)cin >> A[i];

	long long ans = 0;
	rep(i, N) {
		dp[i + 1][A[i]] = i + 1;
		for (int j = 1; j < S; j++) {
			(dp[i + 1][j] += dp[i][j]) %= MOD;
			if (j + A[i] <= S) (dp[i + 1][j + A[i]] += dp[i][j]) %= MOD;
		}

		ans += (long long)dp[i + 1][S] * (N - i);
		ans %= MOD;
	}

	cout << ans << endl;



	return 0;
}