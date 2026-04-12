#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int G[9][9];
int n,m;
int ans;
main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;cin>>a>>b;
		G[a][b]=G[b][a]=1;
	}
	vector<int>v(n);
	for(int i=0;i<n;i++)v[i]=i+1;
	do{
		if(v[0]==1)
		{
			int flag=1;
			for(int i=0;i<n-1;i++)
			{
				if(G[v[i]][v[i+1]]==0)flag=0;
			}
			if(flag==1)ans++;
		}
	}while(next_permutation(v.begin(),v.end()));
	cout<<ans<<endl;
}
