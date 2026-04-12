#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<list>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;
#define REP(i,m,n) for(int i = (m); i < (n);i++)
#define rep(i,n) REP(i,0,n)

class State {
public:
	vector<int> visited;
	int visitedCount;
	int current;
	
	State(int _n,int _start){
		visited.resize(_n,0);
		current = _start;
		visitedCount = 0;
	}
	void Visit(int _next) {
		visited[_next] = 1;
		visitedCount++;
	}
	bool OK() {
		return visitedCount == visited.size();
	}
};

int main() {
	int n,m;
	cin >> n >> m;
	vector<int> graph;
	graph.resize(n*n,0);
	rep(i,m) {
		int from,to;
		cin >> from >> to;
		graph.at((from-1)*n+(to-1)) = 1;
		graph.at((to-1)*n+(from-1)) = 1;
	}
	int start = 0;
	int result = 0;
	stack<State> status;
	rep(i,n) {
		if(graph.at(start*n+i) != 1) continue;
		State st(n,i);
		st.Visit(0);
		st.Visit(i);
		status.push(st);
	}
	while(!status.empty()) {
		State cur = status.top(); status.pop();
		if(cur.OK()) {
			result++;
			continue;
		}
		rep(i,n) {
			if(!(graph.at(cur.current*n+i)==1 && cur.visited[i] != 1))continue;
			State ne = cur;
			ne.Visit(i);
			ne.current = i;
			status.push(ne);
		}
	}
	cout << result << endl;
	
	
	return 0;
}
