#include <iostream>
#include <queue>

using namespace std;

int main() {

	int N, shortest, largest, sum, tmp;

	while (true) {
		cin >> N;
		if (N == 0)
			break;

		sum = 0;
		shortest = 10000;
		largest = -1000;

		for (int i = 0; i < N; i++) {
			cin >> tmp;
			sum += tmp;
			shortest = min(shortest, tmp);
			largest = max(largest, tmp);
		}

		sum -= shortest;
		sum -= largest;

		cout << sum / (N - 2) << endl;

	}

	return 0;
}

