#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int r, g, b;
	cin >> r >> g >> b;

	int n = 100 * r + 10 * g + b;

	cout << (n % 4 ? "NO" : "YES") << endl;
}