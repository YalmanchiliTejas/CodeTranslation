#include <iostream>
using namespace std;

int main() {

	int N;
	int H[210];

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
	}

	int max = 0;
	int count = 0;
	for (int i = 0; i < N; ++i) {
		if (max <= H[i]) {
			max = H[i];
			count += 1;
		}
	}
	cout << count << endl;
}