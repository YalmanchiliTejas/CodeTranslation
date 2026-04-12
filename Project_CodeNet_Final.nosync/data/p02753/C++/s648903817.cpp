#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ll long long
int main()
{
	char a[3];
	cin>>a;
	int c1=0,c2=0;
	for(int i=0;i<3;i++)
	{if(a[i]=='A')
	c1++;
	else
	c2++;}
	if(c1>0 && c2>0)
	cout<<"Yes";
	else
	cout<<"No";
	
	
}