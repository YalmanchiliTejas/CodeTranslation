#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX 10
#define WHITE 0
#define BLACK 1

bool L[MAX][MAX];
int color[MAX];
int N,M,ans;


void dfs(int s){
  int count=0;
  for(int i=0;i<N;i++){
    if(color[i]==BLACK) count++;
  }
  if(count==N) {
    ans++; return;
  };

  
  for(int i=1;i<N;i++){
    if(L[s][i]==false) continue;
    if(color[i]==BLACK) continue;
    color[i]=BLACK;
    dfs(i);
    color[i]=WHITE;
  }
  return;
}

int main(){
  for(int i=0;i<MAX;i++){
    for(int k=0;k<MAX;k++){
      L[i][k]=false;
    }
  }
  int a,b;
  cin>>N>>M;
  for(int i=0;i<M;i++){
    cin>>a>>b;
    a--; b--;
    L[a][b]=true;
    L[b][a]=true;
  }
  color[0]=BLACK;
  dfs(0);
  cout<<ans<<endl;
  
}
