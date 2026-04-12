#include <iostream>
using namespace std;
int main() {
	int n, r, q;
	cin >> n;
	r = n % 15;
	q = (n - r) / 15;
	cout << n * 800 - q * 200 << endl;
	return 0;
}