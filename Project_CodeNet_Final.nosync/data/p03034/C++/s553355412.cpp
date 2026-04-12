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

using namespace std;

//const long long int MOD = 1000000007;
const int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	long long int ans = 0;
	for (int i = 1; i < N; i++) {
		long long int sum = 0;
		for (int j = 1; j *i < N; j++) {
			R = N - 1 - i * j;
			L = R - i;
			sum += v[R];
			sum += v[i*j];
			if (L >= R || L <= 0)continue;
			if (R%i == 0 && i*j >= R)break;
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
}
