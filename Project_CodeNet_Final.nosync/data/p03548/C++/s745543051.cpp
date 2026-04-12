#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
	int_least32_t x, y, z;
	cin >> x >> y >> z;

	x -= z;

	cout << x / (y + z) << endl;
}
