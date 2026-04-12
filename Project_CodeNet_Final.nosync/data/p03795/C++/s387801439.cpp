#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	if (N <= 14) {
		cout << 800 * N << endl;
	}
	if (15 <= N && N <= 29) {
		cout << 800 * N - 200 << endl;
	}
	if (30 <= N && N<= 44) {
		cout << 800 * N - 400 << endl;
	}
	if (45 <= N && N<= 59) {
		cout << 800 * N - 600 << endl;
	}
	if (60 <= N && N<= 74) {
		cout << 800 * N - 800 << endl;
	}
	if (75 <= N && N<= 89) {
		cout << 800 * N - 1000 << endl;
	}
	if (90 <= N) { cout << 800 * N - 1200 << endl;
	}


	return 0;
}