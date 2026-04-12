#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	for (size_t i = 1; i < str.size();++i) {
		if (str[i - 1] == 'A'&&str[i] == 'C') {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}