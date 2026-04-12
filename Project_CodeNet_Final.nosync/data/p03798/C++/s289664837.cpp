#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9+7, MAX = 1e18, larg = 1e5, INF = -1e18;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;

char func(char prev, char ox, char beast) {
	bool flag = true;
	if (prev == 'W') flag = !flag;
	if (ox == 'x') flag = !flag;
	if (beast == 'W') flag = !flag;
	if (flag) return 'S';
	else return 'W';
}

char tmp[100000];
int main() {
	cin >> N;
	string s;
	cin >> s;
	tmp[0] = 'S';
	tmp[1] = 'S';
	rep(i, N - 2) {
		tmp[i + 2] = func(tmp[i], s[i + 1], tmp[i + 1]);
	}
	if (tmp[0] == func(tmp[N - 2], s[N - 1], tmp[N - 1]) && tmp[1] == func(tmp[N - 1], s[0], tmp[0])) {
		cout << tmp;
		return 0;
	}
	tmp[0] = 'W';
	tmp[1] = 'W';
	rep(i, N - 2) {
		tmp[i + 2] = func(tmp[i], s[i + 1], tmp[i + 1]);
	}
	if (tmp[0] == func(tmp[N - 2], s[N - 1], tmp[N - 1]) && tmp[1] == func(tmp[N - 1], s[0], tmp[0])) {
		cout << tmp;
		return 0;
	}
	tmp[0] = 'S';
	tmp[1] = 'W';
	rep(i, N - 2) {
		tmp[i + 2] = func(tmp[i], s[i + 1], tmp[i + 1]);
	}
	if (tmp[0] == func(tmp[N - 2], s[N - 1], tmp[N - 1]) && tmp[1] == func(tmp[N - 1], s[0], tmp[0])) {
		cout << tmp;
		return 0;
	}
	tmp[0] = 'W';
	tmp[1] = 'S';
	rep(i, N - 2) {
		tmp[i + 2] = func(tmp[i], s[i + 1], tmp[i + 1]);
	}
	if (tmp[0] == func(tmp[N - 2], s[N - 1], tmp[N - 1]) && tmp[1] == func(tmp[N - 1], s[0], tmp[0])) {
		cout << tmp;
		return 0;
	}
	cout << -1;
}
