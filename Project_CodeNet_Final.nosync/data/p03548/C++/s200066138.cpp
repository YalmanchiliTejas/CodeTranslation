#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;
	int answer = (X - Z) / (Y + Z);
	cout << answer << endl;
	return 0;
}