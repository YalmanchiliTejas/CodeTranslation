#include <iostream>

using namespace std;

int main()
{
	int x, y, z;
	cin >> x >> y >> z;

	int num = 0;
	int p = 0;
	for (;;)
	{
		if (num >= x)
		{
			p--;
		    break;
		}
		
		num += z + y;
		p++;
	}
	num -=z+y;
	if (num + z > x)
	{
		p--;
	}
	cout << p << endl;
}