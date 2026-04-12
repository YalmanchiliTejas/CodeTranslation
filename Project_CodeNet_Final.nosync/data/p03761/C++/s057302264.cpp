#include <bits/stdc++.h>
using namespace std;
#define pb push_back
bool bo[100];
#define ll long long 
#define mod 1000000007

int main()
{
	int n;
	cin>>n;
	vector<string>v(n+10);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	string s="";
	for(int i='a';i<='z';i++)
	{
		int mi=INT_MAX;
		for(int j=0;j<n;j++)
		{
			int c=0;
			for(int k=0;k<(int)v[j].size();k++)
			{
				if(v[j][k]==i) c++;
			}
			if(c!=0)
			{
				mi=min(c,mi);
			}
			else
			{
				mi=0;
				break;
			}
		}
		s+=string(mi,i);
	}
	cout<<s<<endl;
}