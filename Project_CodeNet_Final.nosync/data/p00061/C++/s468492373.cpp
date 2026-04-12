#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back

using namespace std;

int main()
{
	vector<int> res;
	int v[101];
	int a,b;
	char c;

	while(cin >> a >> c >> b)
	{
		if(a == 0 && b == 0) break;
		
		v[a] = b;
		if(res.empty())
		{
			res.pb(b);
		}
		else
		{
			vector<int>::iterator ite = find(res.begin(),res.end(),b);
			if(ite == res.end())
			{
				res.pb(b);
			}
		}
	}

	sort(res.begin(),res.end(),greater<int>());
	int team;
	while(cin >> team)
	{
		rep(i,res.size())
		{
			if(res[i] == v[team])
			{
				cout << i+1 << endl;
			}
		}
	}


	return 0;
}