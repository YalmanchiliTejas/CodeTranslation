#include <bits/stdc++.h>
#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
using namespace std;
const int INF = sizeof(int) == sizeof(long long) ? 1e18 : 1e9;
const int MOD = 1000000007;
const long double EPS = 1e-8;


int main() {
	int n;
	while(cin >> n, n) {
		int macs = -1, mini = INF, sum = 0, s;
		rep (i, n) {
			cin >> s;
			macs = max(macs, s);
			mini = min(mini, s);
			sum += s;
		}
		cout << (sum - macs - mini) / (n - 2) << endl;
	}
	return 0;
}
