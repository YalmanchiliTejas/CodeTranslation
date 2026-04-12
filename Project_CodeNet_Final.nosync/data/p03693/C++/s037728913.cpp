#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<map>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<numeric>
using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	if ((10 * g + b) % 4 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}