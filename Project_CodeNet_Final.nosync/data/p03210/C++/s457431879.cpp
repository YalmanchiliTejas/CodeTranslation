#define _USE_MATH_DEFINES
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <time.h>
using namespace std;

int main(){ 
	int X;
	cin >> X;
	if (X == 3 || X == 5 || X == 7)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}