#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	int len = S.size();
	bool flag = false;
	for (int i = 0; i < len - 1; i++) {
		if (S.substr(i, 2) == "AC") {
			flag = true;
		}
	}
	if (flag) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}