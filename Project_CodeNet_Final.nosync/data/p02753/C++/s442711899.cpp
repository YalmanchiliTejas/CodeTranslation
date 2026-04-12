#include <iostream>
#include <string>

using namespace std;


int main() {
	string state;

	cin >> state;

	if (state[0] == state[1] && state[1] == state[2]) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}

	return 0;
}