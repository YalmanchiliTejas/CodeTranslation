#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ans=0,sum=0,c1=0,c=0,n,p=1,i,j,a,b,q,k,l,m,g[100][100]={0},v[100];
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		g[a][b]=1;
		g[b][a]=1;
	}
	for(i=0;i<n;i++)
	v[i]=i+1;
	do{
		c=0;
		for(i=1;i<n;i++)
		{
			if(g[v[i]][v[i-1]])
			c++;
		}
		if(c==n-1)
		c1++;
	}while(next_permutation(v+1,v+n));
	printf("%d",c1);
}
