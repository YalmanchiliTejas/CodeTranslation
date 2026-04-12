#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<numeric>
#include<iomanip>
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	x = x - 1;
	int a = x / (y + z);
	if (a*(y + z) + z > x + 1) {
		cout << a - 1 << endl;
	}
	else {
		cout << a << endl;
	}

}