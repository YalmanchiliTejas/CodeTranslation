#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

class point{
private:
	int next_num;
public:
	int next[9];
	point();
	void add_next(int i);
	int get_next_num();
};

point::point(){
	next_num = 0;
}
void point::add_next(int i){
	next[next_num] = i;
	next_num++;
}
int point::get_next_num(){
	return next_num;
}


bool visited[9];
point nodes[9];
int ans = 0;

void dfs(int i, int n);

int main(){
	int n, m;

	cin >> n >> m;

	int in, out;
	REP(i, m){
		cin >> in >> out;
		nodes[in].add_next(out);
		nodes[out].add_next(in);
	}
	REP(i, n){
		visited[i] = false;
	}
	visited[1] = true;
	dfs(1, n);
	cout << ans << endl;

	return 0;
}

void dfs(int i, int n){
	bool all_visited = true;
	for(int j = 1; j <= n && all_visited; ++j){
		if(!visited[j]) all_visited = false;
	}
	if(all_visited){
		ans++;
	}else{
		for(int k = 0; k < nodes[i].get_next_num(); ++k){
			if(!visited[nodes[i].next[k]]){
				visited[nodes[i].next[k]] = true;
				dfs(nodes[i].next[k], n);
				visited[nodes[i].next[k]] = false;
			}
		}
	}

}
