#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, y;
	cin >> n;
	int cashback = n/15;
	y = cashback*200;
	x = n*800;
	cout << x-y << endl;
	return 0;
}