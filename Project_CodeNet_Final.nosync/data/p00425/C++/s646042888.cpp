#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<iostream>

using namespace std;

int dice[6] = { 1, 2, 3, 4, 5, 6 };


int main()
{
	int n, i, tmp, total;
	string order;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)break;
		total = 1;
		dice[0] = 1; dice[1] = 2; dice[2] = 3;
		dice[3] = 4; dice[4] = 5; dice[5] = 6;
		for (i = 0; i < n; i++)
		{
			cin >> order;
			if (order == "North")
			{
				tmp = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[4];
				dice[4] = tmp;
			}
			else if (order == "East")
			{
				tmp = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = tmp;
			}
			else if (order == "West")
			{
				tmp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = tmp;
			}
			else if (order == "South")
			{
				tmp = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[1];
				dice[1] = tmp;
			}
			else if (order == "Right")
			{
				tmp = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[4];
				dice[4] = dice[3];
				dice[3] = tmp;
			}
			else
			{
				tmp = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[4];
				dice[4] = dice[2];
				dice[2] = tmp;
			}
			total += dice[0];
		}
		printf("%d\n", total);
	}
	return 0;
}