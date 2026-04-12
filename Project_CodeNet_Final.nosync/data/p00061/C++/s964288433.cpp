#include <iostream>
#include <set>
#include <vector>
#include <functional>

using namespace std;
typedef pair<int, int> P;

void solve()
{
	vector<P> Vec;
	set<int, greater<int> > Set;
	P p;
	while(~scanf("%d,%d", &p.first, &p.second))
	{
		if(!p.first && !p.second)
		{
			break;
		}
		Vec.push_back(p);
		Set.insert(p.second);
	}
	int n;
	while(cin >> n)
	{
		int count = 0;
		for(set<int, greater<int> >::iterator Ite = Set.begin(); Ite != Set.end(); ++Ite)
		{
			++count;
			if(*Ite == Vec[n - 1].second)
			{
				break;
			}
		}
		cout << count << endl;
	}
}

int main()
{
	solve();
	return(0);
}