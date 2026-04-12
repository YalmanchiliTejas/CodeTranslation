#include <bits/stdc++.h>
using namespace std;



int dfs(vector<set<int>> graph, vector<int> seen, int x){
  
  int n=int(seen.size())-1;
  seen.at(x)=1;
  
  int count=0;
  
  for (int i=1;i<=n;i++){
    count+=seen.at(i);
  }
  
    
  
  
  if (count==n){
    return 1;
  }
  
  bool flag=false;
  for (int nextx:graph.at(x)){
    if (seen.at(nextx)==0){
      flag=true;
      break;
    }
  }
  
  
  if (flag==false and count!=n){
    return 0;
  }
  
  int tmp=0;
  for (int nextx:graph.at(x)){
    if (seen.at(nextx)==0){
    tmp+=dfs(graph,seen,nextx);
    }
  }
  
  

  
  return tmp;
}



int main(){
  
  int n,m;
  cin>>n>>m;
  

  vector<set<int>> graph(n+1);
  
  for (int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph.at(a).insert(b);
    graph.at(b).insert(a);
  }
  
  vector<int> seen(n+1,0);
  seen.at(0)=1;

  
  
  int answer=dfs(graph,seen,1);
  
  cout<<answer<<endl;
  
    
  
  
  
  
  
  
  
    
  
  
  
}