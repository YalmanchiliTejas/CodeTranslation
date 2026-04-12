#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <stdio.h>

using namespace std;

//typedefリスト
typedef vector<int> vint;
typedef vector<string> vstr;


int main(void) {
	long long int X, Y, Z,num;
	cin >> X >> Y >> Z;
	num = X - Z;
	cout << num / (Y + Z) << endl;
}