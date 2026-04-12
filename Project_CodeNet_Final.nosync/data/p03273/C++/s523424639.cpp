#include<bits/stdc++.h>
using namespace std;
char mm[500][500];
bool vis[500][500];
int main()
{   
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	cin>>mm[i][j];
	for(int i=0;i<n;i++)
	{ bool flag=0;
	  for(int j=0;j<m;j++)
	  {
	  	if(mm[i][j]=='#'){
		  flag=1;break;
		  }
	  }
	  if(!flag)for(int k=0;k<m;k++)vis[i][k]=1;
	 }
	 for(int i=0;i<m;i++)
	{ bool flag=0;
	  for(int j=0;j<n;j++)
	  {
	  	if(mm[j][i]=='#'){
		  flag=1;break;
		  }
	  }
	  if(!flag)
	  for(int k=0;k<n;k++)vis[k][i]=1;
	 }
	for(int i=0;i<n;i++)
	{bool dy=0;
	 for(int j=0;j<m;j++)
	if(!vis[i][j])
	{cout<<mm[i][j];dy=1;
	}
	 if(dy)cout<<endl;
	}
	 return 0;
 } 