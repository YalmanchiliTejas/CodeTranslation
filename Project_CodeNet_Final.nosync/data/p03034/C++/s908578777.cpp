#include "bits/stdc++.h"
using namespace std;
const int INF = 1 << 30;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	long long ans = -1e18;
	for (int i = 1; i < N - 1; ++i) {//C
		long long score = 0;
		set<int>s;
		for (int x = 0;; ++x) {//K
			//範囲外
			if (N - 1 - x * i < 0) {
				break;
			}
			//範囲外
			if ((x * i) >= N) {
				break;
			}
			//aの確認
			int a = N - 1 - i * x;
			if (a <= 0) {
				break;
			}
			//bの確認
			int b = a - i;
			if (b <= 0) {
				break;
			}
			//重複チェック
			if (s.count(x * i)) {
				break;
			}
			s.insert(x*i);
			//重複チェック
			if (s.count(N - 1 - x * i)) {
				break;
			}
			s.insert(N - 1 - x * i);
			//計算
			score += A[x * i];
			score += A[N - 1 - x * i];
			ans = max(ans, score);
		}
	}
	cout << ans << endl;
	return 0;
}

