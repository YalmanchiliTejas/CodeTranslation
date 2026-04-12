#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	int h[100];

	int count = 0;
	int maxv = 0;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		if (maxv <= h[i]) {
			maxv = h[i];
			count++;
		}
	}

	cout << count << endl;

	return 0;
}