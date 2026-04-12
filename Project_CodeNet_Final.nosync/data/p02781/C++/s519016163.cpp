#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;

string n;
int k;

long dp[110][2][9];

int main()
{
	cin >> n >> k;

	dp[0][1][0] = 1;
	for (int i = 0; i < (int)n.size(); ++i) {
		for (int j = 0; j < 2; ++j) {
			int x = (j ? n[i] - '0' : 9);
			for (int a = 0; a <= x; ++a) {
				for (int b = 0; b <= k; ++b) {
					if (a != 0) dp[i + 1][j && (a == x)][b + 1] += dp[i][j][b];
					else dp[i + 1][j && (a == x)][b] += dp[i][j][b];
				}
			}
		}
	}

	cout << dp[(int)n.size()][0][k] + dp[(int)n.size()][1][k];
	return 0;
}