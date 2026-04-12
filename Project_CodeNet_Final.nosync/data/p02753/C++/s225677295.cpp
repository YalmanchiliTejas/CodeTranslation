#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int a=0,b=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='A')
		{
			a++;
		}
		if(s[i]=='B')
		{
			b++;
		}
	}
	if(a==2||b==2)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
}