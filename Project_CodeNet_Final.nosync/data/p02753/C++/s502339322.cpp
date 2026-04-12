
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long 
const int MAX=1e9+7;
const int mod=1e9+7;


int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	string s;
	cin>>s;
	int sum=0;char c=s[0];
	for(int i=1;i<s.size();i++)
	{
		if(c!=s[i])
		sum++;
	}
	if(sum>0)
	cout<<"Yes";
	else cout<<"No";
	
}

