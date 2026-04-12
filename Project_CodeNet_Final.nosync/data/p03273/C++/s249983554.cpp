#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int f[510][510];
int x[510],y[510];
int main()
{	
 	int n,m;
 	scanf("%d%d",&n,&m);
 	char c;
 	int z;
 	for(int i=1;i<=n;i++)
 	{
 		z=0;
 		for(int j=1;j<=m;j++)
 		{
 			cin>>c;
 			if(c=='#')f[i][j]=1;
 			else f[i][j]=0;
 			z+=f[i][j];
		 }
		 x[i]=z;
	 }
	 for(int i=1;i<=m;i++)
	 {
	 	z=0;
	 	for(int j=1;j<=n;j++)
	 	{
	 		z+=f[j][i]; 
		 }
		 y[i]=z;
	 }
	 for(int i=1;i<=n;i++)
	 {
	 	if(x[i]==0)continue;
	 	for(int j=1;j<=m;j++)
	 	{
	 		if(y[j]==0)continue;
	 		if(f[i][j]==1)cout<<"#";
	 		else cout<<".";
		 }
		 cout<<endl;
	 }
}