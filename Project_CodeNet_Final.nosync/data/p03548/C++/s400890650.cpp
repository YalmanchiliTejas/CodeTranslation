#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;

	X -= Z * 2;
	int n = Y + Z;
	int m = X / n + X % n / Y;

	cout << m << endl;
}