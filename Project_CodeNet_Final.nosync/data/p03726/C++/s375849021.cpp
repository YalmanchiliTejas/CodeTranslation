#include<bits/stdc++.h>
using namespace std;
int n,f[100010],p;
vector<int> a[100010];
inline void dfs(int i,int j)
{
	int k;
	for(k=0;k<a[i].size();k++)
	  if(a[i][k]!=j)
	    {
		 dfs(a[i][k],i);
		 if(!f[a[i][k]])
		   if(!f[i])
		     f[i]=1;
		   else
		     p=1;
		}
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	  {
	   scanf("%d%d",&j,&k);
	   a[j].push_back(k);
	   a[k].push_back(j);
	  }
	dfs(1,0);
	if(p || !f[1])
	  printf("First\n");
	else
	  printf("Second\n");
	return 0;
}
