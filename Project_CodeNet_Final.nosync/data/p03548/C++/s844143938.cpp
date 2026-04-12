#include<iostream>

using namespace std;

int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;

	int H = 1;
	while (1) {
	
		if (H > (X - Z) / (Y + Z)) {
			break;
		}
		H++;
	}

	cout << H-1 << endl;
	
}
