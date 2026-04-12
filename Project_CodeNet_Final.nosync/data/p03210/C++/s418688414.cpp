#include <iostream>

using namespace std;

void solve()
{
	int X;
	cin >> X;
	if (X == 3 || X == 5 || X == 7)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}

int main()
{
	solve();
	return(0);
}