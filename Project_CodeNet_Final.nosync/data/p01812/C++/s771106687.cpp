#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <map>
using namespace std;

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	
	vector<int> dark(m);
	map<int, int> rdark;
	for(int i=0; i<m; i++){
		cin >> dark[i];
		rdark[dark[i]] = i;
	}	
	vector<vector<int> > v(n+1, vector<int>(k));
	for(int i=1; i<=n; i++){
		for(int j=0; j<k; j++){
			cin >> v[i][j];
		}
	}
	
	vector<vector<int> > adj(1<<m);
	for(int i=1; i<(1<<m); i++){
		for(int j=0; j<k; j++){
			int next=0;
			for(int s=0; s<m; s++){
				if((i&(1<<s)) != 0 && rdark.count(v[dark[s]][j])!=0){
					next |= 1<<rdark[ v[dark[s]][j] ];
				}
			}
			adj[i].push_back(next);
		}
	}
	
	queue<pair<int, int> > search;
	search.push(make_pair(0, (1<<m)-1));
	vector<bool> used(1<<m, false);
	used[(1<<m)-1] = true;
	while(!search.empty()){
		int step = search.front().first;
		int node = search.front().second;
		search.pop();
		if(node==0){
			cout << step << endl;
			break;
		}
		for(int i=0; i<(int)adj[node].size(); i++){
			if(!used[adj[node][i]]){
				search.push(make_pair(step+1, adj[node][i]));
				used[adj[node][i]] = true;
			}
		}
	}
	
	return 0;
}