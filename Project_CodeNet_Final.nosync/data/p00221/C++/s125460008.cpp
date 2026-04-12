#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

string correct(int i)
{
	if(i % 15 == 0)
	{
		return("FizzBuzz");
	}
	else if(i % 3 == 0) 
	{
		return("Fizz");
	}
	else if(i % 5 == 0) 
	{
		return("Buzz");
	}
	else
	{
		stringstream ss;
		ss << i;
		return ss.str();
	}
}

void solve()
{
	int n , m;
	while(cin >> m >> n, m || n)
	{
		int player[1001];
		for(int i = 0; i < 1000; ++i)
		{
			player[i] = 1;
		}
		int remain = m;
		int now_player = 0;
		for(int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			if(remain <= 1) 
			{
				continue;
			}
			if(s != correct(i + 1))
			{
				player[now_player] = 0;
				--remain;
			}
			++now_player;
			if(now_player >= m) 
			{
				now_player = 0;
			}
			while(player[now_player] == 0)
			{
				++now_player;
				if(now_player >= m) 
				{
					now_player = 0;
				}
			}
		}
		bool first = false;
		for(int i = 0; i < m; ++i)
		{
			if(player[i] == 1) 
			{
				cout << (first ? " " : "") << i + 1;
				first = true;
			}
		}
		cout << endl;
	}
}

int main(void)
{
	solve();
	return 0;
}