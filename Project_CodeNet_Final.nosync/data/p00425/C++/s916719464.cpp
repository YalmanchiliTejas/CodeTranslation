#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dice[6] = { 1, 2, 3, 4, 5, 6 };
void roll(string order)
{
	int tmp;
	if (order == "North")
	{
		tmp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = tmp;
	}
	if (order == "West")
	{
		tmp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = tmp;
	}
	if (order == "South")
	{
		tmp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = tmp;
	}
	if (order == "East")
	{
		tmp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = tmp;
	}
	if (order == "Left")
	{
		tmp = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[4];
		dice[4] = dice[2];
		dice[2] = tmp;
	}
	if (order == "Right")
	{
		tmp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[4];
		dice[4] = dice[3];
		dice[3] = tmp;
	}
}

int main()
{
	int n;
	while (cin >> n, n)
	{
		for (int i = 0; i < 6; i++) dice[i] = i + 1;

		string order;
		int ans = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> order;
			roll(order);
			ans += dice[0];
		}
		cout << ans << endl;
	}

	return 0;
}