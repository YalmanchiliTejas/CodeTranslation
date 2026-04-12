#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	int x = r * 100;
	int y = g * 10;
	int ans = x + y + b;
	if (ans % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}