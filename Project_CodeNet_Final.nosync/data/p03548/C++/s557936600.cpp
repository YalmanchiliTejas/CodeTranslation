#include<cstdio>
#include<iostream>

using namespace std;

int main(void) {

	int x, y, z, num;
	cin >> x >> y >> z;

	num = (x - z) / (y + z);

	cout << num << "\n";

	return 0;
}