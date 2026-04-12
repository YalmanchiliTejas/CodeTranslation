#include <iostream>

#include <map>
#include <string>

#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cinttypes>


using namespace std;

int solve(int k, string n)
{
	int ans = 0;

	if (k == 1)
	{
		ans += n[0] - '0';
		ans += 9 * (n.size() - 1);
	}
	else if (k == 2)
	{
		ans += (n[0] - '0' - 1) * (n.size() - 1) * 9;

		int i, j;

		for (i = 1; i < n.size(); ++i)
		{
			j = n[i] - '0';

			if (j != 0)
				break;
		}

		if (i < n.size())
		{
			ans += j;

			if (i + 1 < n.size())
			{
				ans += (n.size() - i - 1) * 9;
			}
		}

		ans += (n.size() - 1) * (n.size() - 2) / 2 * 81;
	}
	else
	{
		ans += (n[0] - '0' - 1) * (n.size() - 1) * (n.size() - 2) / 2 * 81;
		ans += (n.size() - 1) * (n.size() - 2)* (n.size() - 3) / 6 * 729;

		int i, j;

		for (i = 1; i < n.size(); ++i)
		{
			j = n[i] - '0';

			if (j != 0)
				break;
		}

		ans += solve(2, n.substr(i));
	}

	return ans;
}

int main()
{
	string n;
	cin >> n;

	int k;
	cin >> k;

	cout << solve(k,n) << endl;

	return 0;
}
