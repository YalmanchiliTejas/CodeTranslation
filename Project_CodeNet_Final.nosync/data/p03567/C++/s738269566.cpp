#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	string a;
	cin>>a;
	for(int i=0;i<=a.length();i++)
	{
		if(a[i]=='C')
		{
			if(a[i-1]=='A')
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
}