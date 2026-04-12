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
#include "iomanip"
#include "cmath"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	L = 0;
	R = 1000000;
	while (R - L > 1) {
		long long int mid = (L + R + 1) / 2;
		if (mid*M + K*(mid + 1) <= N) {
			L = mid;
		}
		else {
			R = mid;
		}
	}
	cout << L << endl;
	return 0;
}
