#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
	int r, g, b;
	cin >> r >> g >> b;
	int num = r * 100 + g * 10 + b;
	if (num % 4 == 0)
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