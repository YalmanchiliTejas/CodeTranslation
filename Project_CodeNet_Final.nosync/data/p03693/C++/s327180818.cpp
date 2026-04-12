#include <cstdio>
#include <cmath>

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int r, g, b;
	cin >> r >> g >> b;
	int res = r * 100 + g * 10 + b;

	if (res % 4 == 0)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}