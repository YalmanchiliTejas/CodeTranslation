#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

struct unionfind{
	vector<int> data;
	vector<int> size;
	unionfind(int n){
		for(int i=0;i<n;i++){
			data.push_back(i);
			size.push_back(1);
		}
	}
	
	int find(int x){
		if(data[x]==x)return x;
		return data[x]=find(data[x]);
	}
	
	bool unite(int x,int y){
		x=find(x);y=find(y);
		if(x==y)return false;
		data[x]=y;
		size[y]+=size[x];
		return true;
	}
	
	bool check(int x,int y){
		return (find(x)==find(y));
	}
	
	int get_size(int x){
		int X = find(x);
		return size[X];
	}
};


void dfs(vector<vector<long long>> &ans,vector<vector<pair<int,long long>>> &E,int now,int parent,int first,long long maxi){
	
	ans[first][now] = maxi;
	
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i].first;
		long long c = E[now][i].second;
		if(to==parent)continue;
		dfs(ans,E,to,now,first,max(maxi,c));
	}
	
}


int main(){
	int N,M;
	cin>>N>>M;
	
	vector<pair<long long,pair<int,int>>> V;
	
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		long long c;
		cin>>c;
		
		V.emplace_back(c,make_pair(a,b));
	}
	
	vector<vector<pair<int,long long>>> E(N,vector<pair<int,long long>>());
	unionfind uf(N);
	
	sort(V.begin(),V.end());
	long long sum = 0;
	for(int i=0;i<M;i++){
		int a=V[i].second.first,b=V[i].second.second;
		long long cost = V[i].first;
		
		if(uf.unite(a,b)){
			sum+=cost;
			E[a].emplace_back(b,cost);
			E[b].emplace_back(a,cost);
		}
	}
	
	vector<vector<long long>> ans(N,vector<long long>(N,0));
	
	for(int i=0;i<N;i++){
		dfs(ans,E,i,-1,i,0);
	}
	
	int Q;
	cin>>Q;
	
	for(int i=0;i<Q;i++){
		int s,t;
		cin>>s>>t;
		s--;t--;
		
		cout<<sum - ans[s][t]<<endl;
	}
	
		
	
	return 0;
}
