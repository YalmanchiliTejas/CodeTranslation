#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	int noh = 0;
	int res = 0;
	for (int i = 0; i < N; ++i) {
		int H;
		cin >> H;
		if (H >= noh) {
			++res;
			noh = H;
		}
	}
	cout << res << endl;
	return 0;
}

