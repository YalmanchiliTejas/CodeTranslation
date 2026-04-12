#include<bits/stdc++.h>
using namespace std;
main()
{
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<m;j++)
		{
			if(s[j] == '.')
			arr[i][j] = 1;
			else
			arr[i][j] = 2;
		}
	}
	vector<int> r;
	vector<int> c;
	for(int i=0;i<n;i++)
	{
		int c =0;
		for(int j=0;j<m;j++)
		{
			if(arr[i][j] == 2)
			{
				c++;
				break;
			}
		}
		if(c != 0)
		{
			r.push_back(i);
		}
	}
	for(int i=0;i<m;i++)
	{
		int c1 =0;
		for(int j=0;j<n;j++)
		{
			if(arr[j][i] == 2)
			{
				c1++;
				break;
			}
		}
		if(c1 != 0)
		{
			c.push_back(i);
		}
	}
	string arr1[r.size()];
	for(int i=0;i<r.size();i++)
	{
		string s2;
		for(int j=0;j<c.size();j++)
		{
			
			if(arr[r[i]][c[j]] == 1)
			{
				//cout<<".";
				s2 += '.';
			}
			else
			{
				//cout<<"#";
				s2 += '#';
			}
		}
		arr1[i] = s2;
		//cout<<endl;
	}
	for(int i=0;i<r.size();i++)
	{
		cout<<arr1[i]<<endl;
	}
}