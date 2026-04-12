
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll MOD;
const int sz = 2e5;
void mult(ll &a, ll b) {
	a = ((a % MOD) * (b % MOD)) % MOD;
}
void add(ll &a, ll b) {
	a = ((a % MOD) + (b % MOD)) % MOD;
}
ll n, x, found[sz], dp[sz];

int main() {
	fast;
	cin >> n >> x >> MOD;
	ll crsm = 0;
	foru(i, 0, n) {
		if (found[x]) {
			ll len = (ll)i - found[x], fit = (n - i) / len, segSum = dp[i - 1] - (found[x] ? dp[found[x] - 1] : 0);
			crsm += fit * segSum;
			ll rem = (n - i) % len;
			if (rem) {
				if (found[x]) {
					crsm += dp[found[x] + rem - 1] - dp[found[x] - 1];
				}
				else {
					crsm += dp[found[x]+rem - 1];
				}
			}
			break;
		}
		found[x] = i;
		crsm += x;
		dp[i] = crsm;
		mult(x, x);
	}
	cout << crsm << endl;
	return 0;
}