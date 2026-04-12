#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,i,j;
char c[N][N];
bool han[N],lie[N];
int main()
{
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>c[i];
	for(i=0;i<n;i++)
	{
		bool f=true;
		for(j=0;j<m;j++)
			if(c[i][j]=='#')f=false;
		han[i]=f;
	}
	for(j=0;j<m;j++)
	{
		bool f=true;
		for(i=0;i<n;i++)
			if(c[i][j]=='#')f=false;
		lie[j]=f;
	}
	for(int i=0;i<n;i++)
	{
		if(han[i])continue;
		for(int j=0;j<m;j++)
		{
			if(lie[j])continue;
			cout<<c[i][j];
		}
		cout<<endl;
	}
	return 0;
}