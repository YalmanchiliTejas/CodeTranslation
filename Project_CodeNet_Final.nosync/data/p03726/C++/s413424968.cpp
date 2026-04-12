#include<bits/stdc++.h>
using namespace std;

vector<int> e[100001];

int m[100001];

void First(){
	cout<<"First"<<endl;
	exit(0);
}

void dfs(int x,int p){
	for(int it:e[x])
		if(it!=p)
			dfs(it,x);
	if(m[x]==0){
		if(m[p]!=0)
			First();
		m[x]=p;
		m[p]=x;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,e[u].emplace_back(v),e[v].emplace_back(u);
	dfs(1,0);
	if(m[0]!=0)	First();
	cout<<"Second"<<endl;
}
