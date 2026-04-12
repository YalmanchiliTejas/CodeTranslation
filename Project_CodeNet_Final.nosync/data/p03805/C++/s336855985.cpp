#include <iostream>
using namespace std;

bool path[8][8];
int cnt,n;

void search(int d,int prev,bool visited[]){
    int i;
    if(d==n){
        cnt++;
        return;
    }
    for(i=1;i<n;i++){
        if(visited[i]==0&&path[prev][i]==1){
            visited[i]=1;
            search(d+1,i,visited);
            visited[i]=0;
        }
    }
    return;
}

int main(void){
  int m,i,a,b;
  cin>>n>>m;
  for(i=0;i<m;i++){
    cin>>a>>b;
    a--;
    b--;
    path[a][b]=1;
    path[b][a]=1;
  }
  
  bool visited[8]={1};
  search(1,0,visited);
  cout<<cnt<<endl;
  return 0;
}
