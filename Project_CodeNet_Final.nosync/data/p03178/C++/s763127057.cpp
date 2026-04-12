#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const double EPS = 1e-6;
const int MAX_D = 105;

namespace modOp {
    ll add(ll a, ll b, ll mod = MOD) { return (a + b) % mod; }
    ll sub(ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod; }
    ll mul(ll a, ll b, ll mod = MOD) { return (ll)a * b % mod; }
}
using namespace modOp;

string K;
int D;
ll dp[MAX_D][2][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> K >> D;
	dp[0][0][0] = 1;
	for (int i = 0; i < K.size(); ++i) {
		for (int sum = 0; sum < D; ++sum) {
			for (bool flag: {true, false}) {
				for (int digit = 0; digit <= 9; ++digit) {
					if (digit > K[i] - '0' && !flag) break;
					dp[add(sum, digit, D)][flag || (digit < K[i] - '0')][1] = add(dp[sum][flag][0], dp[add(sum, digit, D)][flag || (digit < K[i] - '0')][1]);
				}
			}
		}
		for (int sum = 0; sum < D; ++sum) {
			for (bool flag: {true, false}) {
				dp[sum][flag][0] = dp[sum][flag][1];
				dp[sum][flag][1] = 0;
			}
		}
	}

	cout << sub(add(dp[0][0][0], dp[0][1][0]), 1) << '\n';

	return 0;
}