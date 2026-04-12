#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> P;

void solve()
{
	int n;
	while(cin >> n, n)
	{
		vector< vector<int> > Vec(n, vector<int>(n));
		P p;
		p.first = n / 2;
		p.second = n / 2;
		p.second++;
		int count = 1;
		Vec[p.second][p.first] = count;
		int step = n * n - 1;
		while(step)
		{
			count++;
			p.first = (p.first + 1) % n;
			p.second = (p.second + 1) % n;
			if(Vec[p.second][p.first] == 0)
			{
				Vec[p.second][p.first] = count;
			}
			else
			{
				--p.first;
				if(p.first == -1)
				{
					p.first += n;
				}
				p.second = (p.second + 1) % n;
				while(Vec[p.second][p.first] != 0)
				{
					--p.first;
					if(p.first == -1)
					{
						p.first += n;
					}
					p.second = (p.second + 1) % n;
				}
				Vec[p.second][p.first] = count;
			}
			step--;
		}
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				printf("%4d", Vec[i][j]);
			}
			cout << endl;
		}
	}
}

int main()
{
	solve();
	return(0);
}