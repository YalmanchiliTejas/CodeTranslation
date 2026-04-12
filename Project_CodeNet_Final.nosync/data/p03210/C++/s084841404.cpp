#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int X;
	cin >> X;

	switch (X)
	{
	case 3:
	case 5:
	case 7:
		cout << "YES" << endl;
		break;
	default:
		cout << "NO" << endl;
		break;
	}

	return 0;
}
