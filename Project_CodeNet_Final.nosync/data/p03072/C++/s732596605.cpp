#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> H;

int main(void) {
	cin >> N;
	H.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> H[i];

	int cnt = 0;
	int max_h = 0;
	for (int i = 0; i < N; ++i) {
		if (H[i] >= max_h) {
			++cnt;
			max_h = H[i];
		}
	}

	cout << cnt << '\n';
	return 0;
}
