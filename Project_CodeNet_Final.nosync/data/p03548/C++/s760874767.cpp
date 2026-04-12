#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	a -= c;
	cout << a / (b + c) << endl;
	return 0;
}