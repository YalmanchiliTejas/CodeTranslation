#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int V,E,s,t,w;
vector<vector<pair<int,int>>> v(10001);
int visited[10001] = {0};
int ans[10001] = {0},d[10001] = {0};

void di(int n){
	visited[n] = 1;
	for(int i=0;i<v[n].size();i++){
		if(visited[v[n][i].first]==0){
			d[v[n][i].first] = d[n]+v[n][i].second;
			di(v[n][i].first);
		}
	}
}

/*void dfs(int n){
	visited[n] = 1;
	for(int i=0;i<v[n].size();i++){
		if(visited[v[n][i].first]==0){
			dfs(v[n][i].first);
			d[n] = max(d[n],d[v[n][i].first]+v[n][i].second);
		}
	}
}
*/
int main(){
	cin >> V;
	for(int i=0;i<V-1;i++){
		cin >> s >> t >> w;
		v[s].push_back({t,w});
		v[t].push_back({s,w});
	}
	di(0);
	int a = 0,b = 0,va = 0,vb = 0;
	for(int i=0;i<V;i++){
		if(va<d[i]){
			a = i;
			va = d[i];
		}
	}
	for(int i=0;i<V;i++){
		visited[i] = 0;
		d[i] = 0;
	}
	di(a);
	for(int i=0;i<V;i++){
		if(vb<d[i]){
			b = i;
			vb = d[i];
		}
	}
	for(int i=0;i<V;i++){
		visited[i] = 0;
		ans[i] = d[i];
		d[i] = 0;
	}
	di(b);
	for(int i=0;i<V;i++){
		ans[i] = max(d[i],ans[i]);
		cout << ans[i] << endl;
	}
}
