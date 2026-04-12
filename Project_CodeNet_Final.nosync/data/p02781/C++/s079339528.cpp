#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
string N;
long long dptable[100][4][2];
long long dp(int i, int j, bool adh) {
	if (j == 0) return 1;
	if (i == N.size()) return 0;
	if (dptable[i][j][adh] != -1) return dptable[i][j][adh];
	if (adh) return dptable[i][j][adh] = dp(i + 1, j, N[i] == '0') + (N[i] == '0' ? 0 : ((N[i] - '0' - 1) * dp(i + 1, j - 1, false) + dp(i + 1, j - 1, adh)));
	else return dptable[i][j][adh] = dp(i + 1, j, adh) + 9 * dp(i + 1, j - 1, adh);
}
int main() {
	memset(dptable, -1, sizeof dptable);
	int K;
	cin >> N >> K;
	cout << dp(0, K, true);
	return 0;
}