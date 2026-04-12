#include<bits/stdc++.h>
using namespace std;
int n;
string s[50];
map<char,int> mp,mp1;
int main()
{
	cin>>n;
	for(char i='a';i<='z';i++)
	  mp1[i]=100,mp[i]=0;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		for(int j=0;j<s[i].size();j++)
		{
			mp[s[i][j]]++;
		}
		for(char j='a';j<='z';j++)
		{
			mp1[j]=min(mp1[j],mp[j]);
			mp[j]=0;
	    }
	}
	for(char i='a';i<='z';i++)
	{
		if(mp1[i] && mp1[i]!=100)
		  for(int j=0;j<mp1[i];j++)
		    cout<<i;
	}
	cout<<endl;
	return 0;
}