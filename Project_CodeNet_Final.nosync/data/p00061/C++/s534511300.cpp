#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef pair<int, int> P;

void solve()
{
	map<int, int> Map;
	vector<P> Vec;
	set<int> Set;
	P p;
	while(~scanf("%d,%d", &p.second, &p.first))
	{
		if(p.first == 0 && p.second == 0)
		{
			break;
		}
		Vec.push_back(p);
	}
	sort(Vec.begin(), Vec.end());
	int n = Vec.size();
	for(int i = 0; i < n; ++i)
	{
		Set.insert(Vec[i].first);
	}
	int rank = Set.size();
	set<int>::iterator Ite = Set.begin();
	for(int i = 0; i < n; ++i)
	{
		if(*Ite != Vec[i].first)
		{
			++Ite;
			--rank;
		}
		Map[Vec[i].second] = rank;
	}
	int num;
	while(cin >> num)
	{
		cout << Map[num] << endl;
	}
}

int main()
{
	solve();
	return(0);
}