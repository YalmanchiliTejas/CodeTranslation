#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int a;

	cin >> a;

	cout << 800 * a - 200 * (a / 15) << endl;

	return 0;
}