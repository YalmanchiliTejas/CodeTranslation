#include <iostream>

using namespace std;

int main(void) {
	int r,g,b;
	cin >> r >> g >> b;
	r = r*100;
	g = g*10;
	if ((r+g+b)%4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
