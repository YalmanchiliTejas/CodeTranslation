#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
	int x, y, z;

	cin >> x >> y >> z;
	int A = 0;
	x -= z;
	while (1) {
		if (x < y + z)break;
		x -= (y + z);
		A++;
	}
	cout << A << endl;



	return 0;
}