// 7/4 Tuesday
#include <iostream>

using namespace std;

int main(){
	int r, g, b, t;
	bool m1 = true;

	cin >> r >> g >> b;
	t = r * 100 + g * 10 + b;

	while (t >= 0) {
		if (t == 0) {
			cout << "YES" << endl;
			m1 = false;
			break;
		}
		t = t-4;
	}
	if (m1) {
		cout << "NO" << endl;
	}
	return 0;
}