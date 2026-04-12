#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int X, Y, Z;
	int ans = 1;
	cin >> X >> Y >> Z;

	while (ans * Y + (ans + 1) * Z <= X)
	{
		ans++;
	}
	ans--;

	cout << ans << endl;

	return 0;
}
