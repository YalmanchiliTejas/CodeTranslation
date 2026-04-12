#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int main()
{
	int N, M;
	int a, b;
	vector<P> e;
	vector<int> v;
	int count = 0;
	bool flag = false;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		e.push_back(P(a, b));
	}

	for (int i = 1; i <= N; i++)
	{
		v.push_back(i);
	}

	do
	{
		if (v.front() == 1)
		{
			vector<int> v_t;
			v_t = v;
			while (true)
			{
				flag = false;
				for (int i = 0; i < (int)e.size(); i++)
				{
					if (v_t[0] == e[i].first && v_t[1] == e[i].second)
					{
						v_t.erase(v_t.begin());
						flag = true;
						break;
					}
					else if (v_t[1] == e[i].first && v_t[0] == e[i].second)
					{
						v_t.erase(v_t.begin());
						flag = true;
						break;
					}
				}
				if (!flag)
					break;

				if (v_t.size() == 1)
				{
					count++;
					break;
				}
			}
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << count << endl;

	return 0;
}