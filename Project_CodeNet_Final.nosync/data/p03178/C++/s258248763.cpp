#include <iostream>
#include <string>

using namespace std;

const int MOD = 1000000007;
int countAll[10001][100];

int main() {
	string k;
	int D;
	cin >> k >> D;
	countAll[0][0] = 1;
	for (int n = 0; n + 1 < k.size(); n++) {
		for (int r = 0; r < D; r++) {
			for (int x = 0; x < 10; x++)
			{
				countAll[n + 1][(r + x) % D] += countAll[n][r];
				countAll[n + 1][(r + x) % D] %= MOD;
			}
		}
	}
	int answer = MOD - 1;
	int r = 0;
	for (int defined = 1; defined <= k.size(); defined++) {
		for (int x = 0; x < (k[defined - 1] - '0'); x++) {
			answer += countAll[k.size() - defined][r];
			answer %= MOD;
			// r = (r - 1 + D) % D;
			if (r == 0) {
				r = D - 1;
			}
			else {
				r--;
			}
		}
	}
	// consider k (count k if its sum of digits is a multiple of D)
	answer += countAll[0][r];
	answer %= MOD;
	cout << answer << '\n';
	return 0;
}
