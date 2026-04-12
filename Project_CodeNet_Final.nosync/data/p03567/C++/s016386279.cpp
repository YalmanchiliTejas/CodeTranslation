#include <iostream>
using namespace std;

int main() {
	char c[5];
	cin >> c[0] >> c[1] >> c[2] >> c[3] >> c[4];
	for (int i = 0; i != 4; i++) {
		if (c[i] == 'A' && c[i + 1] == 'C') {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}