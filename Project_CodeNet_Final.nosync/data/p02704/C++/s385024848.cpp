#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

int main() {
	// input
	int N; cin >> N;
	vector<int> S(N), T(N);
	vector<ull> U(N), V(N);
	for (int i = 0; i < N; ++i)
		cin >> S[i];
	for (int i = 0; i < N; ++i)
		cin >> T[i];
	for (int i = 0; i < N; ++i)
		cin >> U[i];
	for (int i = 0; i < N; ++i)
		cin >> V[i];
	// solve
	vector<vector<ull>> res(N, vector<ull>(N, 0));
	for (int b = 0; b < 64; ++b) { // 下からb bit目
		vector<vector<bool>> decided(N, vector<bool>(N, false));
		// 各行について確定される場所を確定
		for (int i = 0; i < N; ++i) {
			if (S[i]) {
				if (!(U[i] & (1ull << b))) {
					// i行目のb bit目はすべて0
					for (int j = 0; j < N; ++j)
						res[i][j] &= ~(1ull << b), decided[i][j] = true;
				}
			}
			else {
				if (U[i] & (1ull << b)) {
					// i行目のb bit目はすべて1
					for (int j = 0; j < N; ++j)
						res[i][j] |= (1ull << b), decided[i][j] = true;
				}
			}
		}
		// 各列について確定される場所を確定
		for (int j = 0; j < N; ++j) {
			if (T[j]) {
				if (!(V[j] & (1ull << b))) {
					// j列目のb bit目はすべて1
					for (int i = 0; i < N; ++i)
						res[i][j] &= ~(1ull << b), decided[i][j] = true;
				}
			}
			else {
				if (V[j] & (1ull << b)) {
					// j列目のb bit目はすべて1
					for (int i = 0; i < N; ++i)
						res[i][j] |= (1ull << b), decided[i][j] = true;
				}
			}
		}
		// 未確定のうち、確定して問題ない場所を確定
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if ((!decided[i][j]) && !(((V[j] >> b) & 1ull) ^ ((U[i] >> b) & 1ull))) {
					if ((V[j] >> b) & 1ull)
						res[i][j] |= (1ull << b);
					else
						res[i][j] &= ~(1ull << b);
					decided[i][j] = true;
				}
			}
		}
		// 未確定を調整
		for (int i = 0; i < N; ++i) {
			if (S[i] && (U[i] & (1ull << b))) {
				// i行目に1があるか
				bool ok = false;
				for (int j = 0; j < N; ++j)
					ok |= !!(res[i][j] & (1ull << b));
				if (ok) continue;
				// 1がない場合
				for (int j = 0; j < N; ++j) {
					if (T[j] == 0 && !((V[j] >> b) & 1ull)) { // and 0な列
						ok = false;
						for (int k = 0; k < N; ++k)
							if (k != i)
								ok |= !(res[k][j] & (1ull << b));
						if (ok) {
							res[i][j] |= (1ull << b);
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			if (T[i] && (V[i] & (1ull << b))) {
				bool ok = false;
				for (int j = 0; j < N; ++j)
					ok |= !!(res[j][i] & (1ull << b));
				if (ok) continue;
				for (int j = 0; j < N; ++j) {
					if (S[j] == 0 && !((U[j] >> b) & 1ull)) {
						ok = false;
						for (int k = 0; k < N; ++k)
							if (k != i)
								ok |= !(res[j][k] & (1ull << b));
						if (ok) {
							res[j][i] |= (1ull << b);
							break;
						}
					}
				}
			}
		}
	}
	// check
	for (int i = 0; i < N; ++i) {
		ull v = res[i][0];
		for (int j = 1; j < N; ++j) {
			if (S[i]) v |= res[i][j];
			else v &= res[i][j];
		}
		if (v != U[i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = 0; i < N; ++i) {
		ull v = res[0][i];
		for (int j = 1; j < N; ++j) {
			if (T[i]) v |= res[j][i];
			else v &= res[j][i];
		}
		if (v != V[i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	// output
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}