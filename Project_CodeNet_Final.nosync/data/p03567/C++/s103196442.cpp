#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int flag=0;
	for (int i=0;i<s.length()-1;i++)
	{
		if(s[i]=='A'&&s[i+1]=='C')
		flag=1;
	}
	if(flag==1)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
	
} 