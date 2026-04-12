#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	cin >> a;
	for (int i = 0; i < sizeof(a); i++) {
		if (a[i] == 'A'&&a[i + 1] == 'C') {
			cout << "Yes"; return 0;
		}
	}
	cout << "No";
	return 0;
}