#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	cout << (int)(x - z) / (y + z) << endl;

	return 0;
}