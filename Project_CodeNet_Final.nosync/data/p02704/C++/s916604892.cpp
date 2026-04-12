#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <random>
#include <complex>
#include <assert.h>

using namespace std;
typedef unsigned long long ll;
#define endl '\n'

template<typename T>
inline bool chmin(T& x, T a) {
	if (x >= a) { x = a; return true; }
	return false;
}

template<typename T>
inline bool chmax(T& x, T a) {
	if (x <= a) { x = a; return true; }
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);

	int N; cin >> N;
	vector<int> S(N), T(N);
	vector<ll> U(N), V(N);

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> T[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> U[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> V[i];
	}

	vector<vector<ll>> ans(N, vector<ll>(N, 0));

	for (int b = 0; b < 64; b++) {
		ll k = 1; k <<= b;

		vector<vector<bool>> flag(N, vector<bool>(N, false));
		vector<vector<ll>> temp(N, vector<ll>(N, 0LL));

		for (int i = 0; i < N; i++) {
			if (S[i] == 0 && (U[i] & k) == k) {
				for (int j = 0; j < N; j++) {
					temp[i][j] = k;
					flag[i][j] = true;
				}
			}
			if (S[i] == 1 && (U[i] & k) == 0) {
				for (int j = 0; j < N; j++) {
					temp[i][j] = 0;
					flag[i][j] = true;
				}
			}
		}
		for (int j = 0; j < N; j++) {
			if (T[j] == 0 && (V[j] & k) == k) {
				for (int i = 0; i < N; i++) {
					temp[i][j] = k;
					flag[i][j] = true;
				}
			}
			if (T[j] == 1 && (V[j] & k) == 0) {
				for (int i = 0; i < N; i++) {
					temp[i][j] = 0;
					flag[i][j] = true;
				}
			}
		}
		const int M = 100;
		int m;
		for (m = 0; m < M; m++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (flag[i][j]) { continue; }
					if (S[i] == T[j]) {
						temp[i][j] = (S[i] ? k : 0);
						flag[i][j] = true;
					}
					else {
						bool f = rand() >= (RAND_MAX / 2);
						temp[i][j] = (f ? k : 0);
					}
				}
			}
			bool result = true;
			for (int i = 0; i < N; i++) {
				if (result == false) { break; }
				ll t;
				if (S[i] == 0) {
					t = k;
					for (int j = 0; j < N; j++) {
						t &= temp[i][j];
					}
				}
				else {
					t = 0;
					for (int j = 0; j < N; j++) {
						t |= temp[i][j];
					}
				}
				if (t != (U[i] & k)) { result = false; break; }
			}
			for (int j = 0; j < N; j++) {
				if (result == false) { break; }
				ll t;
				if (T[j] == 0) {
					t = k;
					for (int i = 0; i < N; i++) {
						t &= temp[i][j];
					}
				}
				else {
					t = 0;
					for (int i = 0; i < N; i++) {
						t |= temp[i][j];
					}
				}
				if (t != (V[j] & k)) { result = false; break; }
			}
			if (result == true) { break; }
		}

		if (m == M) {
			cout << "-1" << endl;
			return 0;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans[i][j] += temp[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}