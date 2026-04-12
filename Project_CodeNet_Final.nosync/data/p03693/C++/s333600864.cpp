#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	cout << ((10 * y + z) % 4 == 0 ? "YES" : "NO") << endl;
}