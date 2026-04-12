#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int x, y, z;
	int num;
	cin >> x >> y >> z;
	num = (x - z) / (y + z);
	cout << num << endl;
}