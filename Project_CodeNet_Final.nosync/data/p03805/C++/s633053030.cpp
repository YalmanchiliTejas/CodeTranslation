#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > vec(9, vector<int>(9, 0));
vector<int> visit(9, 0);	int n, m;

int dfs(int node, int edge){
	int ans=0;	//cout << node << " " << edge << "\n";
	if(edge==(n-1)){
		bool flag=1;
		for(int i=1;n>=i;i++){
			if(!visit[i]){
				flag=0;	break;
			}
		}
		if(flag){
			return 1;
		}
		return 0;
	}
	for(int i=1;n>=i;i++){
		if(vec[node][i]==1 and visit[i]==0){
			visit[i]=1;	
			ans+=dfs(i, edge+1);
			visit[i]=0;
		}
	}
	visit[node]=0;	return ans;
}

int main(){
	cin >> n >> m;
	for(int i=0;m>i;i++){
		int a, b;	cin >> a >> b;	vec[a][b]=vec[b][a]=1;
	}
	visit[1]=1;	cout << dfs(1, 0);
}