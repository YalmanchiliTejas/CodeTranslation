#include <iostream>
#include <string>
using namespace std;

int main(void) {

	std::string S;
	cin >> S;

	bool answer = true;

	if (S[0] == 'A' && S[1] == 'A' && S[2] == 'A') {
		answer = false;
	}


	if (S[0] == 'B' && S[1] == 'B' && S[2] == 'B') {
		answer = false;
	}

	if (answer == true) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}