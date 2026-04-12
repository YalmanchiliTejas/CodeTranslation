#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using ll = long long;

int main() {
	ll N;
	cin >> N;
	int ans = 0;
	int max_H = 0;
	for (int i=0; i<N; ++i) {
		int H;
		cin >> H;
		if (H >= max_H) {
			ans++;
		}
		max_H = max(H, max_H);
	}
	cout << ans << endl;
	return 0;
}

