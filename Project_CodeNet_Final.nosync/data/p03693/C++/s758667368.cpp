#include <iostream>

using namespace std;

int main()
{
	int r, g, b, num;
	cin >> r >> g >> b;

	num = r * 100 + g * 10 + b;
	cout << ((num % 4 == 0) ? "YES" : "NO") << endl;

	return 0;
}
