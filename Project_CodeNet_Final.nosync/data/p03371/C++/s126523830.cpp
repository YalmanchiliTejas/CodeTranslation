#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int money = min(x, y) * min(a+b, 2*c);
	money += abs(x-y) * min(x > y ? a : b, 2*c);
	cout << money << endl;
	return 0;
}
