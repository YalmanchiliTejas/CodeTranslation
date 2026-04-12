#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <string>
#include<sstream>
#include<algorithm>
#include <vector>
#include <cassert>
#include<cmath>
#include <cstdio>
using namespace std;

int main() {
	int i, j;
	int X, Y, Z;

	cin >> X >> Y >> Z;
	int total = Z;
	int count = 0;

	while (total < X) {
		total += Y + Z;
		if (X >= total) {
			++count;
		}

	}

	cout << count << endl;


}