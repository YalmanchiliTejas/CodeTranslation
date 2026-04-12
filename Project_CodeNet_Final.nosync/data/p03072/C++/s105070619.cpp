#include <iostream>

using namespace std;


int main() {
	int n, h;
	cin >> n;

	int sum = 0, tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> h;
		if (tmp <= h) {
			tmp = h;
			sum++;
		}
	}

	cout << sum << endl;

	//system("pause");

	return 0;
}