#include <iostream>
#include <sstream>

using namespace std;

int main() {
	string str;
	stringstream ss;
	stringstream rgbs;
	getline(cin, str);
	ss << str;
	string color;
	while (getline(ss, str, ' ')) {
		rgbs << str;
	}
	int num;
	rgbs >> num;
	if (num % 4 == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}