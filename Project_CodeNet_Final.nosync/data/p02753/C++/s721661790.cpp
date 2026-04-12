#include<iostream>
#include<cstring> 
using namespace std;
int main()
{
	char s[4];
	int i;
	cin>>s;
	int a=0,b=0;
	for(i=0;i<3;i++)
	{
		if(s[i]=='A')
		a=1;
		if(s[i]=='B')
		b=1;
	}
	if(a==1&&b==1)
	cout<<"Yes";
	else
	cout<<"No";
	
}