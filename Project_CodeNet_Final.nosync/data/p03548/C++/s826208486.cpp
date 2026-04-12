#include <iostream>

using namespace std;

int X, Y, Z;

int main(void)
{
	cin >> X >> Y >> Z;
	
	cout << (X - Z) / (Y + Z) << endl;
	return 0;
}