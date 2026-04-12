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

#define MOD 1000000007

string k;
int d;

int dp[10002][2][101];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> d;

	dp[0][0][0] = 1;
	rep(i, k.size()) rep(f, 2)rep(m, d + 1) {
		rep(di, 10) {
			if (f == 0 && k[i] - '0' < di)break;
			(dp[i + 1][f || k[i] - '0' > di][(m + di) % d] += dp[i][f][m]) %= MOD;
		}
	}
	cout << (dp[k.size()][0][0] + dp[k.size()][1][0] - 1 + MOD) % MOD << endl;


	return 0;
}
