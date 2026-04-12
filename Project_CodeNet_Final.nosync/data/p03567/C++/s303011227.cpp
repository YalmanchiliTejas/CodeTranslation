
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string s;

	cin >> s;

	if (s.find("AC") == string::npos) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}