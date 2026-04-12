#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		int dice[6] = { 1, 2, 3, 5, 4, 6 };
		string str;
		int sum = 1;
		for (int i = 0; i != n; ++i)
		{
			cin >> str;
			if (str == "North")
			{
				int temp = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[3];
				dice[3] = temp;
			}
			if (str == "South")
			{
				int temp = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[1];
				dice[1] = temp;
			}
			if (str == "East")
			{
				int temp = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[2];
				dice[2] = temp;
			}
			if (str == "West")
			{
				int temp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[4];
				dice[4] = temp;
			}
			if (str == "Right")
			{
				int temp = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[3];
				dice[3] = dice[4];
				dice[4] = temp;
			}
			if (str == "Left")
			{
				int temp = dice[1];
				dice[1] = dice[4];
				dice[4] = dice[3];
				dice[3] = dice[2];
				dice[2] = temp;
			}
			sum += dice[0];
		}
		cout << sum << endl;
	}
	return 0;
}