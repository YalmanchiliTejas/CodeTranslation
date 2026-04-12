#include <iostream>
#include <string>

using namespace std;


int main()
{
	string s;
	cin >> s;
	string judge = s.substr(0, 1);
	bool yes = false;

	for (int i = 1; i < 3; i++) {
		if (s.substr(i, 1) != judge) {
			yes = true;
		}
	}

	if (yes) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
}