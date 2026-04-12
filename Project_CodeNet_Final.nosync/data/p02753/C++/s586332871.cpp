//@author yash
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
	fast();
	string s;
	cin>>s;
	int cnt=0;
	int cnt1=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='A')
		cnt++;
		else
		cnt1++;
	}
	if(cnt==s.length()||cnt1==s.length())
	cout<<"No"<<endl;
	else
	cout<<"Yes"<<endl;
}

