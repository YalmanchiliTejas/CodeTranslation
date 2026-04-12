#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int x, y, z;
int ta = 0;

int main() {
	cin >> x >> y >> z;
	for (int i = 1;; i++) {
		if (i*y + (i + 1)*z > x) {
			break;
		}
		else {
			ta = i;
		}
	}
	cout << ta << endl;
	return 0;
}