#include <iostream>

using namespace std;

int main()
{
	int N, H[20],viewable = 0,highest=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}

	highest = H[0];

	for (int i = 0; i < N ; i++) {
		if (H[i] >= highest) {
			highest = H[i];
			viewable++;
		}
	}
	cout << viewable  << endl;
	return 0;
}

