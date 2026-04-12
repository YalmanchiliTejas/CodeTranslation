#include<iostream>
using namespace std;
int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;
	for (int i = 0; i < X; ++i) {
		if (i*Y + (i + 1)*Z > X) {
			cout << i - 1 << endl;
			break;
		}
	}
	return 0;
}