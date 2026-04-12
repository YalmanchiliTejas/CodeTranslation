#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N, H[20], ans = 1, m;
	cin >> N >> m;//旅館の数と西の山の高さ//
	for (int i = 1; i < N; i++) {
		cin >> H[i];//山の高さ
		if (H[i] >= m) {
			ans++;
			m = H[i];
		}
	}
	cout << ans << endl;
}