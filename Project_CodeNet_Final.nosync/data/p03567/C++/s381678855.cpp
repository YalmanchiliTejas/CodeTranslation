#include <bits/stdc++.h>
using namespace std;
string s;
bool flag=false;

int main()
{
	cin>>s;
	if(s[0]=='A'&&s[1]=='C')flag=true;
	if(s[1]=='A'&&s[2]=='C')flag=true;
	if(s[2]=='A'&&s[3]=='C')flag=true;
	if(s[3]=='A'&&s[4]=='C')flag=true;
	if(flag==true)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}