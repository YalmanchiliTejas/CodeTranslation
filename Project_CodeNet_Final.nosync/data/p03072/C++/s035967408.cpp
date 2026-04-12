#include <iostream>
using namespace std;

int main() {

	int N;
	cin >> N;

	int H[100];
	int answer = 1;
	int saidai = 0;

	for (int i = 0;i < N;i++) {
		int X;
		cin >> X;
		H[i] = X;

		if (i == 0) {
			saidai = H[0];
		}

		if (i != 0 && saidai <= H[i]) {
			saidai = H[i];
			answer++;
		}
	}

	cout << answer << endl;

	return 0;
}
