#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[100];
int main()
{
	int h,w;
	cin>>h>>w;
	for(int i=0;i<h;i++)cin>>s[i];
	vector<string> ans;
	for(int i=0;i<h;i++)
	{
		bool isw = true;
		for(int j=0;j<w;j++)
		{
			if(s[i][j] == '#')
			{
				isw = false;
				break;
			}
		 } 
		if(!isw)
		{
			ans.push_back(s[i]);
		}
	}
	for(int i=0;i<w;i++)
	{
		bool f = true;
		for(int j=0;j<ans.size();j++)
		{
			if(ans[j][i] == '#')
			{
				f =  false;
				break;
			}
		}
		if(f)
		{
			for(int j=0;j<ans.size();j++)
			{
				ans[j][i] = 'A';
			}
		}
	 } 
	for(int i=0;i<ans.size();i++)
	{
		bool canc = true;
		for(int j=0;j<ans[i].size();j++)
		{
			if(ans[i][j] != 'A')
			{
				cout<<ans[i][j];
			}
		}
		cout<<endl;
	}
	return 0;
}