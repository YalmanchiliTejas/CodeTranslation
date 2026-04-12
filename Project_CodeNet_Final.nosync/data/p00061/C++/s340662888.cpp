#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int t,p,r; char c;
	map<int,int> a;
	map<int,vector<int> > m;
	map<int,vector<int> >::reverse_iterator it;

	while(cin >> t >> c >> p, t||p)
	{
		m[p].push_back(t);
	}

	for(r=1,it=m.rbegin(); it!=m.rend(); r++,it++)
	{
		for(int i=0; i<it->second.size(); i++)
		{
			a[it->second[i]] = r;
		}
	}

	while(cin >> t)
	{
		cout << a[t] << endl;
	}
}