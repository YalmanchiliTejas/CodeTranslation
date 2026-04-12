#include<iostream>
#include<cstring>
#define MaxSize 100
using namespace std;

typedef struct Node* Gmap;
struct Node{
	int N;
	int E;
	int arc[MaxSize][MaxSize];
	char data[MaxSize];
};

Gmap Create(Gmap map,int N,int E,char ch[]){//建图 
	map->N=N;
	map->E=E;
	for(int i=1;i<=N;i++)
		map->data[i]=ch[i];
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			map->arc[i][j]=0;
	return map;
}

void CreatEdge(Gmap &map,int E1,int E2){
	map->arc[E1][E2]=1;
	map->arc[E2][E1]=1;
} 

int cnt=0;
int visited[MaxSize]={0};
void DFS(Gmap map,int v,int k){
	if(k==map->N){
		cnt++;
	}
		
	//cout<<map->data[v]<<" ";
	visited[v]=1;
	for(int j=1;j<=map->N;j++){
		if(!visited[j] && map->arc[v][j]){
			visited[j]=1;
			DFS(map,j,k+1);
			visited[j]=0;
		}
	}
}

char ch[10]={'0','1','2','3','4','5','6','7','8'};
int main(){
	int N,E,E1,E2;
	cin>>N>>E;
	Gmap map=new Node;
	map=Create(map,N,E,ch);
	
	for(int i=0;i<E;i++){
		cin>>E1>>E2;
		CreatEdge(map,E1,E2);
	}

	DFS(map,1,1);
	cout<<cnt<<endl;
	return 0;
}