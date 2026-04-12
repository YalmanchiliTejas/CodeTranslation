#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
	// your code goes here
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	if(s[0]==s[2])
	{
		cout<<"No";	
	}
	else
	{
		cout<<"Yes";
	}
	return 0;
}