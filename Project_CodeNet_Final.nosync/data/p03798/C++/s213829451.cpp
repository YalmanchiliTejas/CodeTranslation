#include <bits/stdc++.h>
typedef long long ll; 
 
using namespace std;

string s;

// i番目まで決まっている状況で、i+1番目を決める
template <typename T>
void func(int i, T& v) {
	if (i >= v.size() - 1) { return; }

	if (v[i] == 0) {
		if (s[i] == 'o') { 
			v[i + 1] = v[i - 1];
		} else { 
			v[i + 1] = 1 - v[i - 1];
		}
	} else if (v[i] == 1) {
		if (s[i] == 'o') {
			v[i + 1] = 1 - v[i - 1];
		} else {
			v[i + 1] = v[i - 1];
		}
	}
	func(i + 1, v);
}

int main() {
	int N; 
	cin >> N >> s;

	for (int i = 0; i < 2; ++i) {
		// 0 := 羊, 1 := 狼
		vector<int> v(N);

		v[0] = i;
		int pre;
		// 初期配置を決める
		for (int j = 0; j < 2; ++j) {
			if (i == 0) {
				if (s[0] == 'o') {
					pre = v[1] = j;
				} else {
					pre = j;
					v[1] = 1 - j;
				}
			} else {
				if (s[0] == 'o') {
					pre = j;
					v[1] = 1 - j;
				} else {
					pre = v[1] = j;
				}
			}

			// N番目まで埋めていく
			func(1, v);

			// 埋めていって決めたN番目と最初に決めたN番目が一致する場合
			if (pre == v[N - 1]) {
				bool can = false;

				if (pre == 0) {
					if (s[N - 1] == 'o') {
						if (v[N - 2] == v[0]) { can = true; }
					} else {
						if (v[N - 2] != v[0]) { can = true; }
					}
				} else {
					if (s[N - 1] == 'o') {
						if (v[N - 2] != v[0]) { can = true; }
					} else {
						if (v[N - 2] == v[0]) { can = true; }
					}
				}

				if (can) {
					for (int i = 0; i < v.size(); ++i) {
						if (v[i] == 0) { cout << 'S'; }
						else { cout << 'W'; }
					}
					cout << endl;
					return 0;
				}
			}
		}
	}

	cout << -1 << endl;
	return 0;
}
