#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main () {
	string s;
	cin >> s;
	if(s == "AAA" || s == "BBB") {
		cout << "No" << "\n";
	}else {
		cout << "Yes" << "\n";
	}
	return 0;
}