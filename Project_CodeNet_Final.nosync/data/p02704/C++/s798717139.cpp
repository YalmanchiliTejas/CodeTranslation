#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>s(N);
	vector<int>t(N);
	vector<unsigned long long int>u(N);
	vector<unsigned long long int>v(N);
	for (auto &i : s)cin >> i;
	for (auto &i : t)cin >> i;
	for (auto &i : u)cin >> i;
	for (auto &i : v)cin >> i;
	vector<vector<unsigned long long int>>ans(N, vector<unsigned long long int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (s[i] && t[j]) {
				ans[i][j] = u[i] & v[j];
			}
			else if (!s[i] && !t[j]) {
				ans[i][j] = u[i] | v[j];
			}
			else if (!s[i]) {
				ans[i][j] = u[i];
			}
			else {
				ans[i][j] = v[j];
			}
		}
	}
	vector<vector<int>>h(N, vector<int>(64));
	vector<vector<int>>w(N, vector<int>(64));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 64; k++) {
				if ((ans[i][j] >> k) & 1) {
					h[i][k]++;
					w[j][k]++;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (s[i] == 0)continue;
		for (int k = 0; k < 64; k++) {
			if (((u[i] >> k) & 1) && !h[i][k]) {
				for (int j = 0; j < N; j++) {
					if (t[j]) continue;
					if (w[j][k] + 1 < N) {
						w[j][k]++;
						ans[i][j] |= 1ULL << k;
						break;
					}
				}
			}
		}
	}
	for (int j = 0; j < N; j++) {
		if (t[j] == 0)continue;
		for (int k = 0; k < 64; k++) {
			if (((v[j] >> k) & 1) && !w[j][k]) {
				for (int i = 0; i < N; i++) {
					if (s[i])continue;
					if (h[i][k] + 1 < N) {
						h[i][k]++;
						ans[i][j] |= 1ULL << k;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (s[i]) {
			unsigned long long int box = 0;
			for (int j = 0; j < N; j++) {
				box |= ans[i][j];
			}
			if (box != u[i]) {
				cout << -1 << endl;
				return 0;
			}
		}
		else {
			unsigned long long int box = ULLONG_MAX;
			for (int j = 0; j < N; j++) {
				box &= ans[i][j];
			}
			if (box != u[i]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	for (int j = 0; j < N; j++) {
		if (t[j]) {
			unsigned long long int box = 0;
			for (int i = 0; i < N; i++) {
				box |= ans[i][j];
			}
			if (box != v[j]) {
				cout << -1 << endl;
				return 0;
			}
		}
		else {
			unsigned long long int box = ULLONG_MAX;
			for (int i = 0; i < N; i++) {
				box &= ans[i][j];
			}
			if (box != v[j]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	for (auto i : ans) {
		for (auto j : i)cout << j << " ";
		cout << endl;
	}
}
