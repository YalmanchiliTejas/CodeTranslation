#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
	int r, g, b;
	cin >> r >> g >> b;

	int all = (100 * r) + (10 * g) + b;
	cout << ((all % 4 == 0) ? "YES" : "NO") << endl;
	return 0;
}
