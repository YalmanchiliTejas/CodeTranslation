#include <iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	if (a % 2 == 1 && 2 < a && 8 > a) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}