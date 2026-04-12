#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int R, G, B;
	cin >> R >> G >> B;

	int ret = R * 100 + G * 10 + B;
	if (ret % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
