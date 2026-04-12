#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	int A, c=0, i;
	cin >> A;
	for (i = A - 1; i > 0; i--) {
		if (A % i == 0)
			c++;
	}
	if (c == 1 && A != 2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}