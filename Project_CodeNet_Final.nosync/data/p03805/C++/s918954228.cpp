#include <bits/stdc++.h>

using namespace std;

int dfs(int now,int a[],int b[],int node_num,int edge_num, bool node[]);
int main(void)
{
	int n,m; cin>>n>>m;
	int a[m],b[m]; for(int i = 0; i < m; i++) cin>>a[i]>>b[i];
	bool node[n]; for(int i = 0; i < n; i++) node[i] = false;
	int ans = dfs(1,a,b,n,m,node);
	
	cout<<ans<<endl;
	return 0;
}

int dfs(int now,int a[],int b[],int node_num,int edge_num,bool node[]){
	//cout<<"now = "<<now<<endl;
	node[now-1] = true;
	/*
	for(int i = 0; i < node_num; i++){
		cout<<"i = "<<i;
		if(node[i] == true) cout<<", node[i] = true"<<endl;
		else cout<<", node[i] = false"<<endl;
	}
	*/
	int kk = 0;
	for(int i = 0; i < node_num; i++){
		if(node[i] == true) kk++;
	}
	if(kk == node_num) return 1;
	int re = 0;
	for(int i = 0; i < edge_num; i++){
		if(a[i] == now && node[b[i]-1] == false){
			bool n_node[node_num]; for(int i = 0; i < node_num; i++) n_node[i] = node[i];
			re += dfs(b[i],a,b,node_num,edge_num,n_node);
		}
		else if(b[i] == now && node[a[i]-1] == false){
			bool n_node[node_num]; for(int i = 0; i < node_num; i++) n_node[i] = node[i];
			re += dfs(a[i],a,b,node_num,edge_num,n_node);
		}
	}
	return re;
}
