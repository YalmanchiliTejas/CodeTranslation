#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

void solve()
{
	vector<P> Vec;
	set<int, greater<int> > Set;
	int num, score;
	while(scanf("%d,%d", &num, &score))
	{
		if(num == 0 && score == 0)
		{
			break;
		}
		Set.insert(score);
		Vec.push_back(make_pair(num, score));
	}
	while(cin >> num)
	{
		for(int i = 0; i < Vec.size(); ++i)
		{
			if(Vec[i].first == num)
			{
				score = Vec[i].second;
				break;
			}
		}
		set<int, greater<int> >::iterator It = Set.begin();
		int count = 1;
		while(It != Set.end())
		{
			if(*It == score)
			{
				cout << count << endl;
			}
			++It;
			++count;
		}
	}
}

int main()
{
	solve();
	return(0);
}