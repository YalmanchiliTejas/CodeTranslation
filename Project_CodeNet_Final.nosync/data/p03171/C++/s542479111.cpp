#include <bits/stdc++.h>
using namespace std;
const int N = 3001;
const long long INF = (long long)1e13;

int n;

int a[N];
long long memo[N][N]; // max X - Y that TARO can obtain from seq i --- j

long long dp (int st, int end) {
	if ((st + 1) == end) {
		memo[st][end] = abs(a[st] - a[end]);
		return memo[st][end];
	}
	if (st == end) {
		memo[st][end] = a[st];
		return a[st];
	}
	if (memo[st][end] != -INF) {
		return memo[st][end];
	}
	long long beg = dp(st + 1, end);
	long long lst = dp(st, end - 1);
	if ((a[st] - beg) > (a[end] - lst))
		memo[st][end] = a[st] - beg;
	else
		memo[st][end] = a[end] - lst;
	return memo[st][end];
}

int main () {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			memo[i][j] = -INF;
	cout << dp(0, n - 1) << "\n";
	return 0;
}