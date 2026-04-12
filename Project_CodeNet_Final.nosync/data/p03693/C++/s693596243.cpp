#include <iostream>

using namespace std;

int main()
{
	int r, g, b, total;
	cin >> r >> g >> b;
	total = r * 100 + g * 10 + b;
	if (total % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}