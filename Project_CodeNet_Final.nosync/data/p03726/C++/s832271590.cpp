#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <cassert>

std::set<int> edges[100005];
int deg[100005];

std::queue<int> leaves;

void remove(int v){
  for(int w:edges[v]){
    edges[w].erase(v);
    if(edges[w].size()==1){
      leaves.push(w);
    }
  }
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].insert(V);
    edges[V].insert(U);
  }
  for(int i=0;i<N;i++){
    if(edges[i].size()==0){
      printf("First\n");
      return 0;
    }
    if(edges[i].size()==1){
      leaves.push(i);
    }
  }
  while(!leaves.empty()){
    int node=leaves.front();
    leaves.pop();
    if(edges[node].empty()){
      printf("First\n");
      return 0;
    }
    int v=*edges[node].begin();
    if(edges[v].size()!=1) remove(*edges[node].begin());
  }
  printf("Second\n");
  return 0;
}
