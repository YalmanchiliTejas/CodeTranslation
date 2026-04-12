#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
#define int long long int
#define mod 1000000007
void dfs(int src,vector<int> adj[],int &here,bool visited[])
{
	if(visited[src])
	   return ;
	else
	{
		visited[src]=true;
		here++;
		for(int x:adj[src])
		   dfs(x,adj,here,visited);
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int j,arr[n];
	for(j=0;j<n;j++)
	   cin>>arr[j];
	int answer=0;
	int sum=0;
	for(j=n-1;j>=0;j--)
	{
		answer+=(sum*arr[j]);
		answer%=mod;
		sum+=arr[j];
		sum%=mod;
	}
	cout<<answer<<endl;
}
