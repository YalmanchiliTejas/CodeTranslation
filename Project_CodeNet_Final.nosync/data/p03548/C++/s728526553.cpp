#include<iostream>
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int i = 1;
	while (x >= y * i + z * (i + 1))i++;
	cout << i-1 << endl;
}