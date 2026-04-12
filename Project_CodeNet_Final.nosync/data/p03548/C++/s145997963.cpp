#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;

	int n;
	n = (x / (y + z));
	if ((y + z)*n + z > x) { n--; }
	cout << n << endl;

}