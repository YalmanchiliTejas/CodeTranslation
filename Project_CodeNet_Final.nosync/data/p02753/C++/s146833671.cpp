#include <bits/stdc++.h>
using namespace std;

signed main()
{
	string s;
	cin>>s;
	
	for (int i=0;i<=s.size()-2;i++)
	{
		for (int j=i+1;j<=s.size()-1;j++)
		{
			if (s[i]!=s[j])
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}