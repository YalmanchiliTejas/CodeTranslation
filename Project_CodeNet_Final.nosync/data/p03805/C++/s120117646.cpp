#include <iostream>
using namespace std;

int D[9][9];
int V[9];
int pathCount;

void dfs(int s,int N,int depth){
  
  if(depth==N){
    pathCount++;
    return ;
  }

  for(int i=2;i<=N;i++){
    if(D[s][i]==1&&V[i]==0){
      V[i]=1;
      dfs(i,N,depth+1);
      V[i]=0;
    }
  }
  
}

int main(){
  int N,M;
  cin>>N>>M;

  for(int i=0;i<M;i++){
    int ai,bi;
    cin>>ai>>bi;
    D[ai][bi]=D[bi][ai]=1;
  }

  pathCount =0;
  V[1]=1;
  dfs(1,N,1);

  cout<<pathCount<<endl;
  return 0;
}
