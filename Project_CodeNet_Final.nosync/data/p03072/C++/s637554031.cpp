#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; i++) cin >> H[i];
	int count = 1;
	for (int i = 1; i < N; i++) {
		bool ok = true;
		for (int j = 0; j < i; j++) {
			if (H[i] < H[j]) ok = false;
		}
		if (ok) count++;
	}
	cout << count << endl;
	return 0;
}