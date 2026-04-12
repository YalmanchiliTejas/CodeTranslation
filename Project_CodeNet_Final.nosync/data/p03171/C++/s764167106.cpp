#include <bits/stdc++.h>
using namespace std;

const int MXN = 3e3 + 20;

long long dp[MXN][MXN];
int n;
vector <long long> a;

long long fill(int i, int j) {
	if (i == j)
		return a[i];
	if (dp[i][j])
		return dp[i][j];
	return dp[i][j] = max(a[i] - fill(i + 1, j), a[j] - fill(i, j -  1));
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	cout << fill(0, n - 1) << endl;
	return 0;
}
