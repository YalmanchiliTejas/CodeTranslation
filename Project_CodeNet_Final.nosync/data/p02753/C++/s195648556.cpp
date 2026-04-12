#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	if (str[0] != str[1] || str[0] != str[2]) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
}