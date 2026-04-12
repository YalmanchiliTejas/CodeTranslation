#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int>adj[8];
bool marked[8];
int n=8,m=28;
int dfs(int s,int c)
{
	marked[s]=true;
	//for(int i=0;i<n;i++)
	//	cout<<marked[i]<<" ";
	//cout<<"\n";
	//cout<<"Vertex "<<s<<" ";
	//cout<<"\n";
	if(c+1==n){
	//	cout<<"\n";
		return 1;
	}
	int sum=0;
	for(auto x : adj[s])
	{
		if(!marked[x]){
			sum += dfs(x,c+1);
		
		marked[x]=false;}
	}
	
	return sum;

}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0;i<n;i++)
		marked[i]=false;
	cout<<dfs(0,0)<<"\n";
}