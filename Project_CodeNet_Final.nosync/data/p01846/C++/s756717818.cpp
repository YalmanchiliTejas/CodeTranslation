#include <bits/stdc++.h>

class Solve {
private:
	using vc = std::vector<char>;
	using vvc = std::vector<vc>;

public:
	bool is_last_query{};
	Solve()
	{
		std::string S;
		std::cin >> S;
		if (S == "#")
		{
			is_last_query = true;
			return;
		}

		vvc board(1);
		for (auto& e: S)
		{
			if (e == '/') board.push_back({});
			else if (e == 'b') board.back().push_back('#');
			else
			{
				for (int i{}; i < e - '0'; i++)
					board.back().push_back('.');
			}
		}
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a--; b--; c--; d--;
		board[a][b] = '.';
		board[c][d] = '#';

		std::string jfen;
		for (auto& e: board)
		{
			jfen += '/';
			for (auto& f: e)
			{
				if (f == '.')
				{
					if ('0' <= jfen.back() && jfen.back() <= '9')
						jfen.back()++;
					else
						jfen.push_back('1');
				}
				else
					jfen.push_back('b');
			}
		}
		for (int i{1}; i < (int)jfen.size(); i++)
			putchar(jfen[i]);
		putchar('\n');
	}
};

int main()
{
	while (!Solve().is_last_query);

	return 0;
}
