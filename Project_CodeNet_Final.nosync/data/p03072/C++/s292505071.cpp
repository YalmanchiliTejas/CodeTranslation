#include <iostream>
#include <vector>

using namespace std;

bool can(const vector<int> &H, int i)
{
	for (int j = 0; j < i; ++j) {
		if (H[j] > H[i]) {
			return false;
		}
	}
	return true;
}

int main()
{
	int N;
	cin >> N;
	vector<int> H(N);
	for (auto &x : H) {
		cin >> x;
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (can(H, i)) {
			++ans;
		}
	}
	cout << ans << endl;
}
