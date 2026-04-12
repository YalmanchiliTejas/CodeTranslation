#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[20];
int main()
{
	int len=0,flag=1;
	cin>>a;
	len=strlen(a);
	for(int i=0;i<len;i++)
		{
			
			if(a[i]=='A'&&a[i+1]=='C')
				{
					cout<<"Yes"<<endl;
					flag=0;
					break;
				}
		}
		if(flag)
		cout<<"No"<<endl; 
}
