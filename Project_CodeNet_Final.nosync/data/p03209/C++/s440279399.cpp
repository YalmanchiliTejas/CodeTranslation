#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const double EPS = 1e-10;
ll solve(int N, ll X) {
	if (X == 0) return 0;
	if (N == 0) return 1;
	if (X == 1) return 0;
	X--;
	if (X < (1LL << (N + 1)) - 3) {
		return solve(N - 1, X);
	}
	else {
		ll ret = (1LL << (N)) - 1;
		X -= (1LL << (N + 1)) - 3;
		if (X > 0) {
			ret++;
			X--;
			ret += solve(N - 1, X);
		}
		return ret;
	}

}
int main() {
	int N;
	ll X;
	cin >> N >> X;
	cout << solve(N, X) << endl;
}