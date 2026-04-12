#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void solve()
{
	int num, correct;
	map<int, int> data;
	set<int> kind;
	while(~scanf("%d,%d", &num, &correct))
	{
		if(num == 0 && correct == 0)
		{
			break;
		}
		data.insert(map<int, int>::value_type(num, correct));
		kind.insert(correct);
	}
	vector<int> correct_desc;
	set<int>::reverse_iterator it = kind.rbegin();
	while(it != kind.rend())
	{
		correct_desc.push_back(*it);
		++it;
	}
	int team;
	while(cin >> team)
	{
		for(int i = 0; i < correct_desc.size(); ++i)
		{
			if(data[team] == correct_desc[i])
			{
				cout << i + 1 << endl;
				break;
			}
		}
	}
}

int main()
{
	solve();
	return(0);
}