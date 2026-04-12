#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
using namespace std;

int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;
	X -= Z;
	cout << X / (Y + Z);
}
