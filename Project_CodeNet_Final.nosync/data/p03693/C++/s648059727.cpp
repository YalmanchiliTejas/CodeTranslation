#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << (((a * 100 + b * 10 + c) % 4 == 0) ? "YES" : "NO") << endl;
	return 0;
}