#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		int sum = 0, maxP = 0, minP = 1000;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			minP = min(minP, x);
			maxP = max(maxP, x);
			sum += x;
		}
		sum -= minP + maxP;
		cout << sum / (n - 2) << endl;
	}
	return 0;
}