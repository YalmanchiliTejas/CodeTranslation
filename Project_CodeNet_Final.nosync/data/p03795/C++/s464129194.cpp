#include <iostream>
#include <algorithm>
//#include <iomanip>
using namespace std;
int main() {

	int n;
	cin >> n;
	int y = n / 15 * 200;

	cout << n * 800 - y << endl;

	return 0;
}