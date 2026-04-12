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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K >> M;
	if (N == 1) {
		cout << K << endl;
		return 0;
	}
	map<int, int>mp;
	mp[K] = 0;
	N--;
	vector<long long int>sum(1, 0);
	sum.push_back(K);
	int cnt = 1;
	while (1) {
		K = K * K%M;
		sum.push_back(sum.back() + K);
		if (mp.find(K) == mp.end()) {
			mp[K] = cnt;
		}
		else {
			if ((N - cnt) % (cnt - mp[K]) == 0) {
				sum.back() += (N - cnt) / (cnt - mp[K])*(sum.back() - sum[mp[K]+1]);
				break;
			}
			mp[K] = cnt;
		}
		if (cnt == N)break;
		cnt++;
	}
	cout << sum.back() << endl;
}