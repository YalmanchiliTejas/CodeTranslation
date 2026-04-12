#include<bits/stdc++.h>
using namespace std;
string str;
int main()
{
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='A' && str[i+1]=='C'){cout<<"Yes"<<endl;return 0;}
	}
	cout<<"No"<<endl;
	return 0;
}