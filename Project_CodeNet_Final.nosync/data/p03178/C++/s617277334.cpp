#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
#include <chrono>
#include <queue>
#include <string>
#include <cassert>
#include <bitset>
#include <stack> 

#define INFLL 2000000000000000000
#define INF 2000000000
#define MOD 1000000007
#define BASE 77747
#define PI acos(-1.0)
#define MAXLEN 29

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;
typedef vector <ll> vll;

string s;
int d;
ll dp[10000][100][2];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> s >> d;
	for (int i = 0; i < s[0] - '0'; i++) {
		dp[0][i % d][0]++;
	}
	dp[0][(s[0] - '0') % d][1] = 1;
	for (int i = 1; i < s.length(); i++) {
		for (int k = 0; k < 10; k++) {
			for (int j = 0; j < d; j++) {	
				dp[i][(j + k) % d][0] += dp[i - 1][j][0];
				dp[i][(j + k) % d][0] %= MOD;
				if (k < s[i] - '0') {
					dp[i][(j + k) % d][0] += dp[i - 1][j][1];
					dp[i][(j + k) % d][0] %= MOD;
				}
				if (k == s[i] - '0') {
					dp[i][(j + k) % d][1] += dp[i - 1][j][1];
					dp[i][(j + k) % d][1] %= MOD;
				}
			}
		}
	}
	cout << (dp[s.length() - 1][0][0] + dp[s.length() - 1][0][1] - 1 + MOD) % MOD << endl;
	return 0;
}