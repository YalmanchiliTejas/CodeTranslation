#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
int main() {
	long long x, y, z;
	cin >> x >> y >> z;
	x -= z;
	cout << x / (y + z) << endl;


	system("pause");
	return 0;
}