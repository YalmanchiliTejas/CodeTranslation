#include<iostream>
#include<string>

using namespace std;

const int nmax=8;
bool pass[nmax][nmax];

int dfs(int v,int n,bool *visited){

  bool all_visited=true;
  for(int i=1;i<n;i++){
   if(!visited[i]) all_visited=false;
  }
  if(all_visited) return 1;
  
  int ret=0;
  for(int i=0;i<n;i++){
   if(!pass[v][i]) continue;
   if(visited[i]) continue;
    
    visited[i]=true;
    ret+=dfs(i,n,visited);
    visited[i]=false;
  }
    
  return ret;

}

int main(){
 int n,m;
  cin >> n >> m;
 
 pass[nmax][nmax]={false};
  for(int i=0;i<m;i++){
   int a,b;
    cin >> a >> b;
    pass[a-1][b-1]=pass[b-1][a-1]=true;
  }
  
  bool visited[nmax]={false};
 
   visited[0]=true;
  
  cout << dfs(0,n,visited) << endl;
   

}