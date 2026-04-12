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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-8;

bool func(int a, int b, string&s) {
	if (a < b) {
		if (s[b - a-1] == '0')return true;
		return false;
	}
	else {
		if (s[a - b-1] == '0')return false;
		return true;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	string s;
	cin >> s;
	vector<int>v(1<<N);
	for (auto &i : v)cin >> i;
	vector<vector<int>>tapi(N, vector<int>(1 << N));
	for (int i = 0; i < 1 << N; i++) {
	//	cout << v[i] << " " << v[(i + 1) % (1 << N)] << endl;
		if (func(v[i], v[(i + 1) % (1 << N)], s)) {
			tapi[0][i] = v[i];
		}
		else {
			tapi[0][i] = v[(i + 1) % (1 << N)];
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 1 << N; j++) {
			if (func(tapi[i - 1][j], tapi[i - 1][(j + (1 << i)) % (1 << N)], s)) {
				tapi[i][j] = tapi[i - 1][j];
			}
			else {
				tapi[i][j] = tapi[i - 1][(j + (1 << i)) % (1 << N)];
			}
		}
	}
	for (auto i : tapi.back())cout << i << endl;
}
