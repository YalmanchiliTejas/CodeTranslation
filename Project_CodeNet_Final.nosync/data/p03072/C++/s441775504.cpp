#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int main() {
	int N;
	int ans = 0;
	int highest = 0;
	cin >> N;
	vector <int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H.at(i);
		if (highest <= H.at(i)) {
			ans++;
			highest = H.at(i);
		}
	}

	cout << ans << endl;

	return 0;
}