#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)
#define MAX_E 30
#define MAX_V 9

struct edge{
  int from, to;
};
edge es[MAX_E];
int V,E;
bool h[MAX_V];

void input_graph(int E){
    int f,t;
    REP(i,E/2){
        cin>>f>>t;
        es[i*2].from=f;
        es[i*2].to=t;
        es[i*2+1].from=t;
        es[i*2+1].to=f;
    }
}

int dfs(int i, int d){
  //cout<<" i:"<<i<<" d:"<<d<<endl;
  if(d==V) return 1;
  int rtn=0;
  REP(j,E){
    if(es[j].from==i&&h[es[j].to]==0){
      h[es[j].to]=1;
      rtn+=dfs(es[j].to,d+1);
      h[es[j].to]=0;
    }
  }
  return rtn;
}

int main(){
  cin>>V>>E;
  E*=2;
  REP(i,MAX_V) h[i]=0;
  h[1]=1;
  
  input_graph(E);
  cout<<dfs(1,1);
  }