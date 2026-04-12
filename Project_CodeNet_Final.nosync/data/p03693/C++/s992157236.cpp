#include <iostream>
#include <cstdio>
using namespace std;

int x, y, z;
int main() {
	cin >> x >> y >> z;
	cout << ((10*y+z) % 4 ? "NO" : "YES");
	return 0;
}
