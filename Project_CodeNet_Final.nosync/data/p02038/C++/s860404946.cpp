#include <iostream>
using namespace std;

int main() {
	int n, i;
	char c;
	
	cin >> n;
	cin >> c;
	for (i = 0; i < n - 1; i++) {
		char x;
		cin >> x;
		if (c == 'T' && x == 'F') c = 'F';
		else c = 'T';
	}
	cout << c << endl;
	return 0;
}
