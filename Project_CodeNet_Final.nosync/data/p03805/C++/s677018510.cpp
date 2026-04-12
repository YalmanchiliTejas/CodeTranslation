#include<bits/stdc++.h>
using namespace std; 


int graph[8][8]; 

int dfs(vector<bool> &vis, int j ,int n)
{
	bool all_visit=true; 
	for(int i=0;i<n;i++)
		if(vis[i]==false) all_visit=false; 

	if(all_visit) return 1 ;
	
	int ret=0; 

	for(int i=0;i<n;i++)
	{
		if(graph[j][i]==false ) continue; 
		if(vis[i]) continue; 

		vis[i]=true; 
		ret+=dfs(vis,i,n);
		vis[i]=false; 
	}	 
	

	return ret; 
}



int main(){

int n; cin>>n; 
int m;cin>>m; 


for(int i=0;i<m;i++)
{	int x, y; 
	cin>>x>>y; 
	graph[x-1][y-1]=graph[y-1][x-1]=true; 
}
vector<bool> vis(n,false);
vis[0]=true;  
cout<<dfs(vis,0,n)<<endl; 
return 0; 
}






