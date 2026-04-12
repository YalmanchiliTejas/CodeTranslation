#include <bits/stdc++.h>
using namespace std;
const int N = 3e3+5;
const long long INF = (long long)1e13;
 
int n;
 
int a[N];
long long dp[N][N];
 
long long f (int i, int j) {
	if ((i + 1) == j) {
		dp[i][j] = abs(a[i] - a[j]);
		return dp[i][j];
	}
	if (i == j) {
		dp[i][j] = a[i];
		return a[i];
	}
	if (dp[i][j] != -INF) {
		return dp[i][j];
	}
	long long beg = f(i + 1, j);
	long long lst = f(i, j - 1);
	if ((a[i] - beg) > (a[j] - lst))
		dp[i][j] = a[i] - beg;
	else
		dp[i][j] = a[j] - lst;
	return dp[i][j];
}
 
int main () {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = -INF;

		
	cout << f(0, n - 1) << "\n";
	return 0;
}