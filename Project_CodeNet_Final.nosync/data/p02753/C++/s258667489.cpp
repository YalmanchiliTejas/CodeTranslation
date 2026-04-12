#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast()    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
	fast()
	string s;
	cin>>s;
	if(s[0]==s[1] &&s[1]==s[2])
	cout<<"No";
	if(s[0]!=s[1] || s[1]!=s[2]|| s[0]!=s[2])
	cout<<"Yes";
}
	
	
	
	
