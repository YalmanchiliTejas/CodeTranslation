#include <bits/stdc++.h>
#define int int64_t
using namespace std;
typedef pair<int, int> P;
const int INF = 100000000;

// グローバル変数


// 関数：


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M, counter;
	cin >> N;
	counter = 0;
	int H[21];
	for (int i=0; i<N; i++) {
		cin >> H[i];
		if (i == 0) {
			M = H[0];
			counter = counter + 1;
		}
		else if (H[i] >= M) {
			M = H[i];
			counter = counter + 1;
		}
	}
	
	cout << counter << endl;
}
