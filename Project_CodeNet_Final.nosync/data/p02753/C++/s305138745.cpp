#include<iostream>
using namespace std;

int main() {
	string s; cin >> s;
	bool a = false, b = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A')a = true;
		if (s[i] == 'B')b = true;
	}
	cout << (a & b ? "Yes" : "No") << endl;

	return 0;
}