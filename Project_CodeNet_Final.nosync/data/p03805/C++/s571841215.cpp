#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<set>
#include<utility>
#include<typeinfo>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=1e9+7;

const int nmax=8;
bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]){
	bool all_visited=true;
	for(int i=0; i<N; i++){
		if(!visited[i]) all_visited=false;
	}
	if(all_visited) return 1;
	int ret=0;
	for(int i=0; i<N; i++){
		if(!graph[v][i]) continue;
		if(visited[i]) continue;
		visited[i]=true;
		ret+=dfs(i, N, visited);
		visited[i]=false;
	}
	return ret;
}

int main(){
	int N, M;
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int A, B;
		cin >> A >> B;
		graph[A-1][B-1]=graph[B-1][A-1]=true;
	}
	bool visited[nmax];
	for(int i=0; i<N; i++) visited[i]=false;
	visited[0]=true;
	cout << dfs(0, N, visited) << endl;

	return 0;
}
