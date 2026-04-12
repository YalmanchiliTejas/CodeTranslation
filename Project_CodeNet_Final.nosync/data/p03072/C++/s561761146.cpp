#include <iostream>

using namespace std;

int main() {

	int n, h[101], answer, highest;

	h[0] = {0};
	cin >> n;
	answer = 0;

	for (int i = 0; i < n;i++) {
		cin >> h[i];
	}
	for (int i = 0; i < n;i++) {

		if (i == 0)highest = h[i];
		if (highest <= h[i]) {
			answer++;
			highest = h[i];
		}
	}
	cout << answer << endl;

	//cin >> /*変数他*/;
	//cout << /*文字列*/ << endl;
	return 0;
}