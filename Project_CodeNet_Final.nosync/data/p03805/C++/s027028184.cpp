#include <bits/stdc++.h>



using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;


//container util
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]){

	bool all_visited = true;

	REP(i,N){
		if(visited[i] == false) all_visited = false;
	}

	if(all_visited) return 1;

	int ret = 0;

	REP(i,N){
		if(graph[v][i] == false) continue;
		if(visited[i]) continue;
		
		visited[i] = true;
		ret += dfs(i,N,visited);
		visited[i] = false;
	}

	return ret;

}


int main(void){

	int N, M; cin >> N >> M;

	REP(i,M){
		int A, B; cin >> A >> B; A--; B--;
		graph[A][B] = graph[B][A] = true;
	}

	bool visited[nmax];
	REP(i,N){
		visited[i] = false;
	}
	
	visited[0] = true;
	cout << dfs(0, N, visited) << endl;

	return 0;

}
