#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

int main() {
	int A;
	cin >> A;
	if (A == 3||A ==5||A==7) {
		cout << "YES" << endl;
	}
	/*else if (A == 24) {
		cout << "Christmas Eve" << endl;
	}
	else if (A == 25) {
		cout << "Christmas" << endl;
	}
	else if (A == 22) {
		cout << "Christmas Eve Eve Eve" << endl;
	}*/
	else {
		cout << "NO" << endl;
	}
	return 0;
}