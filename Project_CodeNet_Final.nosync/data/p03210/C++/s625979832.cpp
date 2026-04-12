#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	int A;
	cin >> A;
	if (A == 3 || A == 5 || A == 7)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}