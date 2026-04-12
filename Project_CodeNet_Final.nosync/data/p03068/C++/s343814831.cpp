#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int k;
	cin>>k;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==s[k-1]) cout<<s[i];
		else cout<<"*";
	}
	cout<<endl;
	return 0;
}