#include<iostream>
#include<algorithm>
#include<vector>
#include<string>


int main() {

	int n = 0;
	std::cin >> n;
	std::vector<std::string>str(n);
	std::vector<std::pair<char, int>>str_char_pair{};

	bool enable = false;
	for (int i = 0; i < n; i++)
	{
		std::cin >> str[i];
		for (char c = 'a'; c <= 'z'; c++)
		{
			int count = std::count(str[i].begin(), str[i].end(), c);

			if (count >= 1) {
				str_char_pair.emplace_back(c, count);
			}
		}
	}
	std::sort(str_char_pair.begin(), str_char_pair.end());
	std::vector<std::pair<char, int>>enable_str_pair;
	for (char c = 'a'; c <= 'z'; c++)
	{
		int count = std::count_if(str_char_pair.begin(), str_char_pair.end(), [&c](std::pair<char, int>p) ->bool {return p.first == c;});
		if (count == n)
		{
			auto it = str_char_pair.begin();
			for (auto i = str_char_pair.begin(); i != str_char_pair.end(); i++)
			{
				bool b = [&c](std::pair<char, int>p) ->bool {return p.first == c;}(*i);
				if (b) {
					it = i;
					break;
				}
			}

			for (size_t i = 0; i < n; i++)
			{
				enable_str_pair.push_back(*(it + i));
			}
		}
	}

	for (char c = 'a'; c <= 'z'; c++)
	{
		for (auto& i : enable_str_pair)
		{
			if (i.first == c)
			{
				for (int j = 0; j < i.second; j++)
				{
					std::cout << c;
					enable = true;
				}
				break;
			}
		}
	}
	if (!enable)std::cout << "";
	std::cout << std::endl;
	
}
