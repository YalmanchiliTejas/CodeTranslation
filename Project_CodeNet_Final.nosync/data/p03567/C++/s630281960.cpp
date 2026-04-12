#include<bits/stdc++.h>
const int MAXN=10000;
using namespace std;

void mainp()
{
	string s;
	cin>>s;
	
	for(int i=0; i<s.size()-1; i++)
	{
		if(s[i]=='A'&&s[i+1]=='C')
		{
			cout<<"Yes"<<endl;
			return;
		}
	}
	
	cout<<"No"<<endl;
	return;
}
int main()
{
	mainp();
	return 0;
}
