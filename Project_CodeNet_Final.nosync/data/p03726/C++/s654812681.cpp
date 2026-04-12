#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
const int N=100009;
vector<int> g[N];
int math[N],c[N],flag=true,n;// c 1 w，0 b； true,second,可以匹配 
void dfs(int u,int fa){

	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa)continue;
		if(flag)dfs(v,u);
		if(u&&c[v]==-1&&c[u]==-1){
			c[v]=0;//染黑 
			c[u]=1;//白	 
			math[v]=u,math[u]=v;
		}
		else if(c[u]==1&&c[v]==-1)flag=false;
	//	else if(!u&&c[v]==-1) flag=false;
	}	
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	} 
	memset(c,-1,sizeof(c));
	dfs(1,0);
	if(c[1]==-1)flag=false;
	if(!flag)cout<<"First\n";
	else cout<<"Second\n";
	
}
 