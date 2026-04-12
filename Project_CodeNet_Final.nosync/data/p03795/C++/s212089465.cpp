#include <bits/stdc++.h>
using namespace std;

int x, y, n, total;

int main () {
	cin >> n;
	x = 800;
	y = n/15*200;
	total = x*n - y;
	cout << total << endl;
}