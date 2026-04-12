#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<climits>
#include<map>
#include<string>
#include<functional>
#include<iomanip>
#include<deque>
#include<random>
#include<set>

using namespace std;
typedef long long ll;
typedef double lldo;
#define mp make_pair
#define pub push_back
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
ll gcd(ll a, ll b) { if (a % b == 0) { return b; } else  return gcd(b, a % b); }
ll lcm(ll a, ll b) { if (a == 0) { return b; }return a / gcd(a, b) * b; }
template<class T>ll LBI(vector<T>& ar, T in) { return lower_bound(ar.begin(), ar.end(), in) - ar.begin(); }
template<class T>ll UBI(vector<T>& ar, T in) { return upper_bound(ar.begin(), ar.end(), in) - ar.begin(); }

string n;
ll k, dp[101][4][2] = {};

int main() {
	cin >> n;
	cin >> k;
	dp[0][0][0] = 1;
	rep(i, sz(n)) {
		rep(j, k + 1) {
			rep(l, 10) {
				if (l == 0) {
					dp[i + 1][j][1] += dp[i][j][1];
					if (n[i] == '0') {
						dp[i + 1][j][0] += dp[i][j][0];
					}
					else {
						dp[i + 1][j][1] += dp[i][j][0];
					}
				}
				else if (j < k) {
					dp[i + 1][j + 1][1] += dp[i][j][1];
					if (l == n[i] - '0') dp[i + 1][j + 1][0] += dp[i][j][0];
					if (l < n[i] - '0') dp[i + 1][j + 1][1] += dp[i][j][0];
				}
			}
		}
	}
	cout << dp[sz(n)][k][0] + dp[sz(n)][k][1] << endl;
	return 0;
}