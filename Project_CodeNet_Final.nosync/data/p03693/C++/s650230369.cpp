#include <iostream>
#include <string>
using namespace std;

int main()
{
	int r, g, b;
	cin >> r >> g >> b;

	int box = 0;
	
	box += (r * 100);
	box += (g * 10);
	box += (b);

	if (box % 4 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
