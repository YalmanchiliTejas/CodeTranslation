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

	cin >> N >> M;
	for (long long int i = M + 1; i <= N; i++) {
		long long int box,bag;
		box = N / i;
		bag = N % i;
		K += box*(i - M);
		K += max((long long int)0, bag - M + 1);
		if (!M) {
			K--;
		}
	}
	cout << K << endl;
	return 0;
}