#include <iostream>

using namespace std;
int r, g, b;

int main(void) {
	int ans = 0;
	cin >> r >> g >> b;
	ans = r * 100 + g * 10 + b;
	if (ans % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}