/*
─────────────────────
───────────████████──
──────────███▄███████
──────────███████████
──────────███████████
──────────██████─────
──────────█████████──
█───────███████──────
██────████████████───
███──████AJ████──█───
███████████████──────
███████████████──────
─█████████████───────
──███████████────────
────████████─────────
─────███──██─────────
─────██────█─────────
─────█─────█─────────
─────██────██────────
─────────────────────
*/

#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

int N;
vector<ll> a;
ll dp[3001][3001];

ll getMaxVal(int start, int end) {
	if (start == end) {
		return a[start];
	}
	if (dp[start][end] != -1) return dp[start][end];
	return dp[start][end] = max(a[start] - getMaxVal(start + 1, end),
	                            a[end] - getMaxVal(start, end - 1));
}

int main() {
	cin >> N;
	a = vector<ll> (N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			dp[i][j] = -1;
		}
	}
	cout << (getMaxVal(0, N - 1)) << endl;
	return 0;
}