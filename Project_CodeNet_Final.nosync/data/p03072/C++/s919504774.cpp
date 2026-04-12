#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#define BUF 1e5
#define INF 1<<30
using namespace std;
ll MOD = 1e9 + 7;
ll A, B, C, D, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S;
ll ans = 0;

int main() {
	cin >> N;
	vector<int>H(N);
	bool flag = 1;
	for (int i = 0; i < N; i++)cin >> H[i];
	for (int i = 0; i < N; i++) {
		flag = 1;
		for (int j = 0; j < i; j++) {
			if (H[i] < H[j]) {
				flag = 0;
			}
		}
		if (flag)ans++;
	}
	cout << ans << endl;
}