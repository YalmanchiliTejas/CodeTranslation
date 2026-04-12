#include <iostream>
#include <list>
using namespace std;
const int nmax = 8;
int N = nmax;
bool graph[nmax][nmax];

int dsf(int v,bool visited[nmax]){
	int i;
	for(i = 0;i < N;++i)if(!visited[i])break;
	if(i == N)return 1;
	int ret=0;
	for (i = 0; i < N; ++i)
	{
		if(visited[i])continue;
		if(!graph[v][i])continue;
		visited[i]=true;
		ret+=dsf(i,visited);
		visited[i]=false;
	}
	return ret;
}

int main(){
	int n,m,a,b;
	
	cin >> N >> m;
	for(int i = 0;i < m;i++){
		cin >> a >> b;
		graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
	}
	bool visited[nmax]={0};
	visited[0] = true;
	cout << dsf(0,visited) << endl;
}