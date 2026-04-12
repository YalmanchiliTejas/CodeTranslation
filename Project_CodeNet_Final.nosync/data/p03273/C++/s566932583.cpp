#include<iostream>
using namespace std;
string s[100];
int h,w,a[100],b[100];
main()
{
	cin>>h>>w;
	for(int i=0;i<h;i++)cin>>s[i];
	for(int i=0;i<h;i++)
	{
		int f=1;
		for(int j=0;j<w;j++)f&=s[i][j]=='.';
		a[i]=f;
	}
	for(int j=0;j<w;j++)
	{
		int f=1;
		for(int i=0;i<h;i++)f&=s[i][j]=='.';
		b[j]=f;
	}
	for(int i=0;i<h;i++)
	{
		if(a[i])continue;
		for(int j=0;j<w;j++)if(!b[j])cout<<s[i][j];
		cout<<endl;
	}
}
