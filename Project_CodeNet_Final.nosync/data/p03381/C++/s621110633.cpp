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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	vector<long long int>w(v);
	for (int i = 0; i < N; i++) {
		w[i] = w[i] * MOD + i;
	}
	sort(w.begin(), w.end());
	vector<int>ans(N);
	for (int i = 0; i < N / 2; i++) {
		ans[w[i] % MOD] = w[N / 2] / MOD;
	}
	for (int i = N / 2; i < N; i++) {
		ans[w[i] % MOD] = w[N / 2-1] / MOD;
	}
	for (auto i : ans) {
		cout << i << endl;
	}
	return 0;
}
