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
#include "iomanip"
#include "cmath"
#include "random"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> H >> W;
	K = H;
	if (K >= N) {
		cout << 1 << endl;
		return 0;
	}
	if (W >= H) {
		cout << "-1\n";
		return 0;
	}
	cout << ((N - H) / (H - W) + !!((N - H) % (H - W))) * 2 + 1 << endl;
	return 0;
}