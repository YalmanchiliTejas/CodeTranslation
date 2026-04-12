#include <iostream>

// #define int long longの会に入会
#define int long long

using namespace std;

int calcBurgerSize(int level)
{
	return level ? 2 * calcBurgerSize(level - 1) + 3 : 1;
}

int countPatties(int level, int x)
{
	if(level == 0)
	{
		return 1;
	}

	int smallSize = calcBurgerSize(level - 1);

	if(x == 1)
	{
		return 0;
	}
	else if(x < 2 + smallSize)
	{
		return countPatties(level - 1, x - 1);
	}
	else if(x == 2 + smallSize)
	{
		return countPatties(level - 1, smallSize) + 1;
	}
	else if(x < 3 + smallSize * 2)
	{
		return countPatties(level - 1, smallSize) + countPatties(level - 1, x - smallSize - 2) + 1;
	}
	else
	{
		return countPatties(level - 1, smallSize) * 2 + 1;
	}
}

signed main()
{
	int n, x;

	cin >> n >> x;

	cout << countPatties(n, x) << endl;
}