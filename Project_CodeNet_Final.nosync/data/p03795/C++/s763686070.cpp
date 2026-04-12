#include<iostream>
using namespace std;
int main() {
	int n, a, x, y, z;
	cin >> n;
    a = n / 15;
	x= 800 * n;
	y = 200 * a;
	z = x - y;
	cout << z << endl;
	return 0;
}