#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <utility>
#include <string>

using namespace std;

int main()
{
	vector<pair<int, pair<int, string> > > team;
	int n, pt[10][3];
	string str[10];
	bool flag = true;

	while(cin >> n)
	{
		if(n == 0)    break;

		if(flag)    flag = false;
		else		cout << endl;

		for(int i = 0; i < n; i++)
			cin >> str[i] >> pt[i][0] >> pt[i][1] >> pt[i][2];

		for(int i = 0; i < n; i++)
			team.push_back(make_pair(((pt[i][0] * -3) - pt[i][2]), make_pair(i, str[i])));

		stable_sort(team.begin(), team.end());

		for(int i = 0; i < n; i++)
			cout << team[i].second.second << "," << -(team[i].first) << endl;
		
		team.clear();
	}

	return 0;
}