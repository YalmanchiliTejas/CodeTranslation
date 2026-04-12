/*
	AOJ502 DICE
*/
#include <iostream>
#include <string>



int main()
{
	while (true) {
		int dice[] = {
			1,2,6,3,5,4
			/*
			1
			2354
			6
			*/
		};
		int n;
		int ans = 1;
		std::cin >> n;
		if (n == 0)
			break;

		for (int i = 0; i < n; ++i)
		{
			std::string s;
			std::cin >> s;

			if (s == "North")
			{
				int buf;
				buf = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[4];
				dice[4] = buf;

			}
			else if (s == "East")
			{
				int buf = dice[0];
				dice[0] = dice[5];
				dice[5] = dice[2];
				dice[2] = dice[3];
				dice[3] = buf;
			}
			else if (s == "West")
			{
				int buf = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[2];
				dice[2] = dice[5];
				dice[5] = buf;
			}
			else if (s == "South")
			{
				int buf = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[2];
				dice[2] = dice[1];
				dice[1] = buf;
			}
			else if (s == "Right")
			{
				int buf = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[4];
				dice[4] = dice[5];
				dice[5] = buf;
			}
			else if (s == "Left")
			{
				int buf = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[4];
				dice[4] = dice[3];
				dice[3] = buf;
			}

			ans += dice[0];
		}

		std::cout << ans << std::endl;
	}
	// std::system("PAUSE");
	return 0;
}