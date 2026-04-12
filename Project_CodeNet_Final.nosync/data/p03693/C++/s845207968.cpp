#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int r, g, b;
	cin >> r >> g >> b;
	if ((10 * g + b) % 4 == 0)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
}