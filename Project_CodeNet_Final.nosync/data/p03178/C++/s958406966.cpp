#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<stdbool.h>
#include<math.h>
#include<sstream>
#include<math.h>
#include<vector>
#include<functional>
#include<queue>
#include<utility>
#include<bitset>
typedef long long ll;
#define N (1000000000+7)
#define INF 1e10
using namespace std;
typedef pair<ll, ll> P;

ll dp[10010][2][110] = { 0 };
int main(void) {
	string s;
	ll d, sum = 0;
	cin >> s >> d;
	dp[0][0][0] = 1;
	for (ll i = 0;i < s.length();i++) {
		ll x = s[i] - '0';
		for (ll j = 0;j < 2;j++) {
			for (ll k = 0;k < d;k++) {
				for (ll l = 0;l <= (j?9 : x);l++) {
					dp[i + 1][j || l < x][(k+l)%d] = (dp[i + 1][j || l < x][(k+l)% d] + dp[i][j][k]) % N;
				}
			}
		}
	}
	
	cout << (dp[s.length()][0][0] + dp[s.length()][1][0] - 1+N)%N << endl;
}