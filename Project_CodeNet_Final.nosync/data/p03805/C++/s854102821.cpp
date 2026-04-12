#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int res = 0;

void dfs(vector<vector<int> > &graph,set<int> visit,int current){
	
	//cout << "--"<<endl;
	//cout << current <<endl;
	visit.insert(current);
	/*
	cout << visit.size() << " " << graph.size() <<endl;
	for(auto a : visit) cout << a << " ";
	cout <<endl;*/
	if(visit.size() == graph.size()){
		res++;
		return;
	}
	
	for(auto next : graph[current]){
		if(visit.find(next) == visit.end()){
			dfs(graph,visit,next);
		}
	}
}

int main(){
	int n,m;
	cin >>n >> m;
	
	
	vector<vector<int> > graph(n);
	int a,b;
	
	for(int i=0;i<m;++i){
		cin >> a >> b;
		a--;b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	set<int> visit;
	
	dfs(graph,visit,0);
	
	cout << res <<endl;
	
	return 0;
}

