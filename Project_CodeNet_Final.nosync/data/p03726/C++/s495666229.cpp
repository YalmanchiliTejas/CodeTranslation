#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000
vector<vector<int>> E;

int dfs(int now,int p){
	int odd = 0;
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i];
		if(to==p)continue;
		int x = dfs(to,now);
		if(x==-1)return -1;
		odd+=x;
	}
	if(odd>1)return -1;
	return odd^1;
}


int main(){
	
	int N;
	cin>>N;
	
	E.resize(N,vector<int>());
	
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	int t = dfs(0,-1);

	if(t==0)cout<<"Second"<<endl;
	else cout<<"First"<<endl;

	
	return 0;
}