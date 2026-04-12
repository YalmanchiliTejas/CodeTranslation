#include <iostream>
#include <cstdlib>

using namespace std;

int X, Y, Z;

void solve()
{
	int res = 1;
	X -= Y + 2 * Z;
	res += X / (Y + Z);
	cout << res << endl;
}


int main()
{
	cin >> X >> Y >> Z;
	solve();
	return 0;
}