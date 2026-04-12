
#include <iostream>
using namespace std;
int N,M;
bool graph[9][9]={};
bool visited[9]={};

int dfs(int v){
	bool all_visited=true;
	for(int i=1;i<=N;i++){
		if(visited[i]==false){
			all_visited=false;
		}
	}
	
	if(all_visited){
		return 1;
	}
	
	int ret=0;
	
	for(int i=1;i<=N;i++){
		if(graph[v][i]==false) continue;
		if(visited[i]) continue;
		
		visited[i]=true;
		ret+=dfs(i);
		visited[i]=false;
		
	}
	
	return ret;
	
}

int main(){
	for(int i=0;i<9;i++){
		visited[i]=false;
		for(int k=0;k<9;k++){
			graph[i][k]=false;
		}
	}
	
	cin >> N >> M;
	int input_1,input_2;
	
	for(int i=1;i<=M;i++){
		cin >> input_1 >> input_2;
		graph[input_1][input_2]=true;
		graph[input_2][input_1]=true;
	}
	
	visited[1]=true;
	cout << dfs(1) << endl;
	
	
	return 0;
}