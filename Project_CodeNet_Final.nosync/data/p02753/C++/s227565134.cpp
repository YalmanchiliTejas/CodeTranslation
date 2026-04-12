#include <bits/stdc++.h>
using namespace std;
int main()
{
	string st;
	cin>>st;
	if(st[0]=='A' && st[1]=='A' && st[2]=='A' || st[0]=='B' && st[1]=='B' && st[2]=='B' )
		cout<<"No";
	else 
		cout<<"Yes";
	return 0;
}
