// #include<bits/stdc++.h>
#include <iostream>
#include<vector>
#include<string>
//#include<algorithm>
//#include<stdio.h>
//#include<cmath>
//#define int long long int
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define umii unordered_map<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pws(x) cout<<x<<" ";
#define pwe(x) cout<<x<<endl;
#define all(arr) arr.begin(),arr.end()
using namespace std;

vector<pair<bool,int> > common(vector<pair<bool,int> > a,vector<pair<bool,int> > b)
{
	for(int i=0;i<26;i++)
	{
		if(a[i].first && b[i].first)
		{
			a[i].second=min(a[i].second,b[i].second);
		}
		else
		{
			a[i].first=0;
		}
	}
	return a;
}

int main()
{
	// #ifndef IO
	// freopen("input2.txt","r",stdin);
	// freopen("output2.txt","w",stdout);
	// #endif

	int t=1;
	cin>>t;
	vector< pair<bool, int> > a(26,make_pair(0,0));
	string str;
	cin>>str;
	t--;
		for(int i=0;i<str.length();i++)
		{
			a[str[i]-'a'].first=1;
			a[str[i]-'a'].second++;			
		}
	while(t--)
	{
		string str;
		cin>>str;
		vector< pair<bool, int> > b(26,make_pair(0,0));
		for(int i=0;i<str.length();i++)
		{
			b[str[i]-'a'].ff=1;
			b[str[i]-'a'].ss++;			
		}
		a=common(a,b);
	}
   	for(int i=0;i<26;i++)
   	{
   		if(a[i].first)
   		{
			while(a[i].second--)
			{
				cout<<char(i+'a');
			}
   		}
   	}
	return 0;
}