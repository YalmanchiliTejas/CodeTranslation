#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <iostream>
#include <sstream>
#include <climits>
#include <cfloat>

typedef long long ll;

using namespace std;

struct team_greater
{
	bool operator()(const pair<int, string>& a, const pair<int, string>& b)
	{
		return a.first > b.first;
	}
};
int main()
{
	bool line_break = false;
	int n;
	while (cin >> n && n)
	{
		if (line_break)
			cout << endl;
		else
			line_break = true;

		pair<int, string> team[16];
		for (int i = 0; i < n; ++i)
		{
			string t;
			int a, b, c;
			cin >> t >> a >> b >> c;
			team[i] = make_pair(a*3 + c, t);
		}
		stable_sort(team, team + n, team_greater());
		for (int i = 0; i < n; ++i)
			cout << team[i].second << ',' << team[i].first << endl;
	}

	return 0;
}