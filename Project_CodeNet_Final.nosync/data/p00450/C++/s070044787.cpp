#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n, n)
	{
		bool c[100001];
		for (int i = 0; i < n; ++i)
		{
			cin >> c[i];
			if ((i + 1) % 2 == 0)
			{
				if (i - 1 >= 0 && c[i - 1] != c[i])
				{
					for (int j = i - 1; j >= 0; --j)
					{
						if (c[j] == c[i])
						{
							break;
						}
						c[j] = c[i];
					}
				}
			}
		}
		cout << count(c, c + n, false) << endl;
	}
}

int main()
{
	solve();
	return(0);
}