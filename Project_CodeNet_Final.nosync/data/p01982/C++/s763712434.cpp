#include "iostream"
#include "random"
#include "string"
#include "bitset"
#include "algorithm"
#include "map"
#include "queue"
#include "list"
#include "set"
#include "climits"
#include "iomanip"
#include "stack"
#include "functional"

using namespace std;

int N, M, K, L, R, H, W;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	while (N) {
		vector<int>v(N);
		for (auto &i : v)cin >> i;
		int ans = 0;
		for (int i = M; i <= K; i++) {
			int st = 10000;
			for (int j = 0; j < N;j++) {
				if (i%v[j] == 0) {
					st = min(st, j);
				}
			}
			if (st == 10000) {
				if (N % 2 == 0)ans++;
			}
			else if (st % 2==0) {
				ans++;
			}
		}
		cout << ans << endl;
		cin >> N >> M >> K;
	}
}
