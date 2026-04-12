#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	int max = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int m;
		cin >> m;
		if (m >= max) {
			sum++;
		}
		max = std::max(max, m);
	}
	cout << sum << endl;
}
