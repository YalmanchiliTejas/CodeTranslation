#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int X, Y, Z;
	cin >> X >> Y >> Z;
	int ans = (X - Z) / (Y + Z);
	cout << ans << endl;
	return 0;
}
