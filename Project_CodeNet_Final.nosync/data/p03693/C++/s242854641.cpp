#include <iostream>
using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	a *= 100;
	b *= 10;

	if ((a + b + c) % 4 == 0)cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}