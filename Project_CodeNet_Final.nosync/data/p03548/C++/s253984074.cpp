#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
using namespace std;
int main() {
	int X, Y, Z, ans;
	cin >> X >> Y >> Z;
	ans = (X - Z) / (Y + Z);
	cout << ans;
}