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



int n;
int a[3000];
long long dp[3001][3001];



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> n;
	rep(i, n)cin >> a[i];

	for (int i = 1; i <= n; i++) rep(j, n-i+1) {
		int size = i;
		if ((n - size) % 2 == 0) {
			auto ret = max(a[j] + dp[i - 1][j + 1], a[j + i - 1] + dp[i - 1][j]);
			dp[i][j] = ret;
		}
		else {
			auto ret = min(dp[i - 1][j + 1], dp[i - 1][j]);
			dp[i][j] = ret;
		}
	}

	auto sum = accumulate(a, a + n, 0LL);

	cout << 2*dp[n][0] -sum << endl;

	return 0;
}
