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
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 262144
#define REP(i,n) for(long long i = 0;i < n;++i)
long long n, k, m;
long long dp[202][202][1 << 12];
int main() {
	cin >> n >> k >> m;
	n *= 2;
	for (int i = n - 1; n - i <= k&&i >= 1; --i) {
		dp[n][i][(1 << (n - i - 1))] = 1;
	}
	for (int i = n; i >= 2; i--) {
		for (int q = i - 1; i - q <= k&&q >= 1; --q) {
			for (int j = 0; j < (1 << k); ++j) {
				if (dp[i][q][j] == 0) continue;
				int left = -1;
				for (int t = 0;;++t) {
					if (((1 << t) & j) == 0) {
						left = t;
						break;
					}
				}
				long long next_t = j >> (left + 1);
				//now taking left
				int next_i = i - left - 1;
				if (i - next_i > k) continue;
				if (next_i <= 0) continue;
				int target = i - q - left - 1;
				for (int t = max(target,0); t < k; ++t) {
					int nya = 1 << t;
					if ((nya& next_t) == 0) {
						//can fit
						int next_q = q - (t-target) - 1;
						if (next_q <= 0) continue;
						if (q - next_q > k) continue;
						if (next_i - next_q > k) continue;
						dp[next_i][next_q][next_t + nya] += dp[i][q][j];
						dp[next_i][next_q][next_t + nya] %= m;
					}
				}
			}
		}
	}
	long long ans = 0;
	for (int i = k + 1; i >= 2; --i) {
		ans += dp[i][1][(1 << (i-1)) - 1];
		ans %= m;
	}
	cout << ans << endl;
	return 0;
}
