#include <iostream>
#include <string>

using namespace std;

int main(void) {

	int r, g, b, rgb;

	cin >> r >> g >> b;

	rgb = r * 100 + g * 10 + b;

	if (rgb % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;

}