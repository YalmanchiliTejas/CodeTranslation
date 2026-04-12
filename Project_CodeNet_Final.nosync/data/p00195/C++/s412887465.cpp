#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int a,b;
	string store[5] = {"A","B","C","D","E"};

	while(cin >> a >> b)
	{
		if(a == 0 && b == 0)
		{
			break;
		}

		vector<pair<int,string> > v;
		v.push_back(make_pair(a+b,store[0]));
		
		REP(i,1,5)
		{
			cin >> a >> b;
			v.push_back(make_pair(a+b,store[i]));		
		}

		sort(v.begin(),v.end(),greater<pair<int,string> >());

		cout << v[0].second << " " << v[0].first << endl;
	}
	return 0;
}