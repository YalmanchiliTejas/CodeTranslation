#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string a[100];
int b[100];
int c[100];
int main()
{
	int n,m;
	cin>>n>>m;
	getchar();
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++)
	getline(cin,a[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
	{
	if(a[i][j]=='#')
	{
		b[i]=1;
		c[j]=1;
	}
	}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
	{
		if(b[i]==0)
		break;
		if(c[j]==0)
		continue;
		if(a[i][j]=='#')cout<<"#";
	else cout<<".";
	
	}
	if(b[i]==1)
	cout<<endl; 
	}


return 0;
}