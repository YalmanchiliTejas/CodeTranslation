#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include<map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 100000000000000
long long dp[2000][2000] = {};
long long inv[2000] = {};
long long done_before[2000] = {};
long long combi[2000][2000] = {};
long long combination(long long a,long long b) {
	if (combi[a][b] != 0) return combi[a][b];
	long long ans = 1;
	for (int i = 0;i < b;++i) {
		ans *= (a - i);
		ans %= MAX_MOD;
	}
	for (int i = 1;i <= b;++i) {
		ans *= inv[i];
		ans %= MAX_MOD;
	}
	return combi[a][b] = ans;
}
int main() {
	long long n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	dp[a-1][n] = 1;
	inv[1] = 1;
	//逆元
	for (int i = 2;i <= n;++i) {
		inv[i] = inv[MAX_MOD%i] * (MAX_MOD - MAX_MOD / i) % MAX_MOD;
	}
	for (long long i = a;i <= b;++i) {
		for (int j = n;j >= 0;--j) {
			if (dp[i - 1][j] != 0) {
				dp[i][j] += dp[i - 1][j];
				dp[i][j] %= MAX_MOD;
				long long multi = 1;
				long long hogee = j;
				for (int q = 0;q < d;++q) {
					if (hogee - i < 0) break;
					multi *= combination(hogee, i);
					multi %= MAX_MOD;
					multi *= inv[q + 1];
					multi %= MAX_MOD;
					hogee -= i;
					if (q >= c - 1) {
						dp[i][hogee] += multi * dp[i - 1][j];
						dp[i][hogee] %= MAX_MOD;
					}
				}
			}
		}
	}
	cout << dp[b][0]%MAX_MOD << endl;
	return 0;
}