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
	cin >> N >> S >> K;
	for (int i = 0; i < N; i++) {
		if (S[K - 1] != S[i])S[i] = '*';
	}
	cout << S;
}