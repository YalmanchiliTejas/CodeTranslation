#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int flag=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='A'&&s[i+1]=='C') flag=1;
	}
	if(flag) cout<<"Yes";
	else cout<<"No";
	return 0;
}