#include <bits/stdc++.h>
using namespace std;

int main () {
	int x, y, n, tot;
	cin >> n;
	y = n / 15 * 200;
	x = n * 800;
	tot = x - y;
	cout << tot << endl;
}