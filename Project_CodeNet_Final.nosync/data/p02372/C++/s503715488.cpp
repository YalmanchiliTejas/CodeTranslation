#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

#define MAXN 10000

using namespace std;

struct edge{
	int nn;
	int w;
	edge(int a, int b){nn = a; w = b;}
};

vector<edge> node[MAXN];

int maxdist[MAXN];
int visited[MAXN];

void DFS(int idx, int w){
	visited[idx] = 1;
	if(w > maxdist[idx]) maxdist[idx] = w;
	
	for(int i = 0; i < node[idx].size(); i++){
		if(visited[node[idx][i].nn]) continue;
		
		DFS(node[idx][i].nn, w + node[idx][i].w);
	}
}

int main(){
	
	int n;
	int x, y, z;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n - 1; i++){
		//cin >> x >> y >> z;
scanf("%d %d %d", &x, &y, &z);
		
		node[x].push_back(edge(y,z));
		node[y].push_back(edge(x,z));
	}
	
	for(int i = 0; i < n; i++){
		if(node[i].size() != 1) continue;
		memset(visited, 0, sizeof(visited));
		DFS(i, 0);
	}
	
	for(int i = 0; i < n; i++){
//cout << maxdist[i] << endl;
printf("%d\n", maxdist[i]);
	}
	return 0;
}