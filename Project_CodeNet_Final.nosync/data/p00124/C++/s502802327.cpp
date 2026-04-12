#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
typedef pair<int, string> P;

void solve()
{
	bool first = true;
	int n;
	while(cin >> n, n)
	{
		vector<P> data;
		set<int> point;
		for(int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			int a, b, c;
			cin >> a >> b >> c;
			int sum = 0;
			sum += a * 3 + c;
			data.push_back(P(sum, str));
			point.insert(sum);
		}
		if(!first)
		{
			cout << endl;
		}
		first = false;
		set<int>::reverse_iterator rit = point.rbegin();
		int pos = 0;
		while(rit != point.rend())
		{
			for(int i = 0; i < n; ++i)
			{
				if(*rit == data[i].first)
				{
					cout << data[i].second << "," << data[i].first << endl;
				}
			}
			++rit;
		}
	}
}

int main()
{
	solve();
	return(0);
}