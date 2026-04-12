//First 3 submissions are of Mahir

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=3e5+5;

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	int n=s.size();
	int check=0;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='A'&&s[i+1]=='C')
			check=1;
	}
	if(check)
		cout<<"Yes";
	else
	{
		cout<<"No";
	}
}