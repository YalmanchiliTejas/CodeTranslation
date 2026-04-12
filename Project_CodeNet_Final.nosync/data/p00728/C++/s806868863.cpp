#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	while (1) {
		int n;
		cin >> n;
		if (n == 0)break;
		int M = 0, m = 2525;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			M = max(a, M), m = min(a, m);
			cnt += a;
		}

		cout << (cnt - M - m) / (n - 2) << endl;
	}
	return 0;
}
