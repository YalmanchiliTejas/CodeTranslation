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
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	M = 99000;
	vector<int>ans;
	while (M>0) {
		if (v.front() < v.back() && v.front()) {
			M--;
			ans.push_back(N - 1);
			swap(v.back(), v.front());
		}
		M--;
		ans.push_back(1);
		auto w = v;
		for (int i = 0; i < N; i++) {
			v[i] = w[(i + 1) % N];
		}
	}
	while (v.front()) {
		ans.push_back(1);
		auto w = v;
		for (int i = 0; i < N; i++) {
			v[i] = w[(i + 1) % N];
		}
	}
	cout << ans.size() << endl;
	for (auto i : ans)cout << i << endl;
}