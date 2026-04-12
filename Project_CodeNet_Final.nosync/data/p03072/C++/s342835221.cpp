#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int N, H, ans = 1, tmp;
	cin >> N >> tmp;
	for (int i = 1; i < N; ++i) {
		cin >> H;
		if (H >= tmp) ++ans;
		tmp = max(H, tmp);
	}
	cout << ans;
}