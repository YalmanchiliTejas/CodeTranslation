#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	int h;
	h = r * 100 + g * 10 + b;
	if (h % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}