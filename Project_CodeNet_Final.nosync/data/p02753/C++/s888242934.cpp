#include <iostream>
#include <string>

using namespace std;

int main()
{
	string n;
	cin >> n;
	
	int c = 0;
	for (int i = 0; i < 3; i++) {
		if (n[i] == 'A') {
			c++;
		}
	}
	
	if (c == 3 || c == 0) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}

	return 0;
}