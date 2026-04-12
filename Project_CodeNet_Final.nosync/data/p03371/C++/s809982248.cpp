#include<iostream>
using namespace std;

int min(int a, int b) {
	return (a < b) ? a : b;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int temp1 = min(a*x + b*y, max(x, y)*c*2);
	int temp2 = c*min(x, y)*2 + a*(x-min(x, y)) + b*(y-min(x, y));
//	cout << temp1 << " " << temp2 << endl;
	cout << min(temp1, temp2) << endl;
}