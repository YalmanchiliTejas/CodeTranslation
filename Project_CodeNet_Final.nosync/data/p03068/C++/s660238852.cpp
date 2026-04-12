#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int k;
	cin>>k;
	char c;
	for(int i=0;i<n;i++)
	{
		if(i==k-1)
			c=s[i];
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]==c)
			cout<<s[i];
		else
			cout<<"*";
	}
	cout<<endl;
}