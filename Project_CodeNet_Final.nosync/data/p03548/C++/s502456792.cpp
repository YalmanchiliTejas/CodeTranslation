#include <iostream>

using namespace std;

int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	int count = 0;
	x -= z;
	count = x / (y + z);

	cout << count << endl;




	return 0;
}