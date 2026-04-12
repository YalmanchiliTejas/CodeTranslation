#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[15], n, w; bool dp[100020];
bool knapsack(vector<int>x) {
	for (int i = 1; i < 100020; i++)dp[i] = false; dp[0] = true;
	for (int i = 0; i < (int)x.size(); i++) {
		for (int j = w - x[i]; j >= 0; j--) {
			if (dp[j] == true)dp[j + x[i]] = true;
		}
	}
	return dp[w];
}
bool solve(int r) {
	vector<int>J;
	for (int i = 0; i < n; i++) {
		int R = r, t = 0;
		while (R >= (1 << t)) {
			R -= (1 << t); t++;
			J.push_back(a[i] * (1 << (t - 1)));
		}
		if (R >= 1)J.push_back(a[i] * R);
	}
	return knapsack(J);
}
int main() {
	while (true) {
		cin >> n >> w; if (n == 0 && w == 0)break;
		for (int i = 0; i < n; i++)cin >> a[i];
		int L = 1, R = w + 10, M;
		while (true) {
			M = (L + R) / 2;
			bool p1 = solve(M), p2 = solve(M - 1);
			if (p1 == true && p2 == false) { cout << M << endl; break; }
			if (p2 == true)R = M;
			if (p1 == false)L = M;
		}
	}
	return 0;
}