#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int X;
	cin >> X;

	bool b = false;
	if (X == 3) b = true;
	if (X == 5) b = true;
	if (X == 7) b = true;

	cout << (b ? "YES" : "NO") << endl;
}