#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<int> g[1000];
int N,M;
bool used[1000];
int out=0;

void find(int s){
  bool h=true;
  for(int i=0;i<N;i++){
    if(!used[i])h=false;
  }
  for(int i=0;i<g[s].size();i++){
    int to=g[s][i];
    if(used[to])continue;
    used[to]=true;
    find(to);
    used[to]=false;
  }
  if(h)out++;
}


int main(){

  cin>>N>>M;
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  used[0]=true;
  for(int i=1;i<N;i++){
    used[i]=false;
  }
  find(0);
  /*
  for(int i=0;i<N;i++){
    cout<<"No_"<<i<<"...";
    for(int j=0;j<g[i].size();j++){
      cout<<g[i][j]<<"...";
    }
    cout<<"turn"<<endl;
  }
  */
  cout<<out<<endl;
}
