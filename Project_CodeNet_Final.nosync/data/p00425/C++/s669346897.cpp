#include <iostream>
#include <vector>
#include <string>

class Sai {
public:
	int up;
	int down;
	int north;
	int east;
	int west;
	int south;

	Sai()
	{
		up = 1;
		down = 6;
		south = 2;
		east = 3;
		north = 5;
		west = 4;
	}
	void North()
	{
		int temp = up;
		up = south;
		south = down;
		down = north;
		north = temp;
	}
	void East()
	{
		int temp = up;
		up = west;
		west = down;
		down = east;
		east = temp;
	}
	void West()
	{
		int temp = up;
		up = east;
		east = down;
		down = west;
		west = temp;
	}
	void South()
	{
		int temp = up;
		up = north;
		north = down;
		down = south;
		south = temp;
	}
	void Right()
	{
		int temp = south;
		south = east;
		east = north;
		north = west;
		west = temp;
	}
	void Left()
	{
		int temp = south;
		south = west;
		west = north;
		north = east;
		east = temp;
	}
};

int main()
{
	int n;
	std::string str;
	std::vector<int> ans;

	while (1) {
		std::cin >> n;
		if (n == 0) {
			break;
		}

		int answer = 1;
		Sai sai;

		for (int i = 0; i < n; i++) {
			std::cin >> str;
			if (str == "North") {
				sai.North();
				answer += sai.up;
			}
			else if (str == "East") {
				sai.East();
				answer += sai.up;
			}
			else if (str == "West") {
				sai.West();
				answer += sai.up;
			}
			else if (str == "South") {
				sai.South();
				answer += sai.up;
			}
			else if (str == "Right") {
				sai.Right();
				answer += sai.up;
			}
			else if (str == "Left") {
				sai.Left();
				answer += sai.up;
			}
		}
		ans.push_back(answer);
	}

	for (unsigned int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << std::endl;
	}

	return 0;
}