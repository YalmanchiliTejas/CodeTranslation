#include <bits/stdc++.h>
using namespace std;

int n, x, y;
int main()
{
	cin >> n;
	x = n * 800;
	y = 200 * (n / 15);
	cout << x - y << endl;

	cin.get();
	return 0;
}