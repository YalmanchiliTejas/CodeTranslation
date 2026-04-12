#include<iostream>
using namespace std;
int main() {
	int r, g, d;
	cin >> r >> g >> d;
	if ((g * 10 + d) % 4 == 0) {
		cout << "YES" << endl;
		return 0;
	}
	else {
		cout << "NO" << endl;
		return 0;
	}
	return 0;
}