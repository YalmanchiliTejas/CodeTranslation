#include<iostream>
using namespace std;
int main()
{
	char s[3];
	int i,j,m=0,n=0;
	for(i=0;i<3;i++)
	{
		cin>>s[i];
		if(s[i]=='A')
		m++;
		else
		n++;
	}
	if(m>0&n>0)
	cout<<"Yes";
	else
	cout<<"No";
	
}