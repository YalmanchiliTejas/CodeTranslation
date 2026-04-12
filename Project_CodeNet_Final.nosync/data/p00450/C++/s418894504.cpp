#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int n, c;
	
	while (true)
	{
		scanf("%d", &n);

		if (n == 0) { break; }

		vector<pair<int, int> > r; // (color, number)

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &c);

			if (i == 0)
			{
				r.push_back(make_pair(c, 1));
			}
			else if (i % 2 == 0)
			{
				if (r.back().first == c)
				{
					r.back().second++;
				}
				else
				{
					r.push_back(make_pair(c, 1));
				}
			}
			else
			{
				if (r.back().first == c)
				{
					r.back().second++;
				}
				else
				{
					int prevc = r.back().first;
					int prevn = r.back().second; r.pop_back();

					if (!r.empty())
					{
						r.back().second += prevn + 1;
					}
					else
					{
						r.push_back(make_pair(c, prevn + 1));
					}
				}
			}
		}

		int ret = 0;

		for (int i = 0; i < r.size(); i++)
		{
			if (r[i].first == 0)
			{
				ret += r[i].second;
			}
		}

		printf("%d\n", ret);
	}

	return 0;
}