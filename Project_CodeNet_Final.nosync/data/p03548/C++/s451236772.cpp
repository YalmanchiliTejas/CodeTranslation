#include <iostream>
#include<sstream>
#include<vector>
#include<iterator>
using namespace std;

int main(void)
{
	int X, Y, Z;
	cin >> X >> Y >> Z;

	int ret = 1;
	X -= Y + 2*Z;

	ret += X/(Y+Z);
	cout << ret << endl;

	return 0;
}
