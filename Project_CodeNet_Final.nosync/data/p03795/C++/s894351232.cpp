#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	int x, y;
	x = 800 * N;
	y = 200 * (N / 15);

	cout << x - y << endl;
}