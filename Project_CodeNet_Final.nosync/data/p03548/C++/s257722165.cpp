#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int X, Y, Z;
int main() {
	cin >> X >> Y >> Z;
	int cur = 0, ret = 0;
	while (cur + Y + Z <= X - Z) cur += Y + Z, ret++;
	cout << ret << endl;
	return 0;
}