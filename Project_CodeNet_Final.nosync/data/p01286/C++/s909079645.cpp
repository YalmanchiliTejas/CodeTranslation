#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stack>

using namespace std;

const double EPS=(1e-10);
typedef long long ll;
typedef pair<int,int> pii;
bool EQ(double a,double b){
  return abs((a)-(b))<EPS;
}
void fast_stream(){
  std::ios_base::sync_with_stdio(0);
}

int H,W,C,M,Nw,Nc,Nm;

const int MAX_V=3001;
const ll INF=1000000000000000LL;

class edge{
public:
  int to,rev;
  ll cap;
  edge(int to_,ll cap_,int rev_){
    to=to_;
    cap=cap_;
    rev=rev_;
  }
};

vector<edge> G[MAX_V];
// sツつゥツづァツづ個仰猟猟」
int level[MAX_V];
// ツづつアツづ慊づ陳イツづ猟終ツづュツづつスツつゥ
int iter[MAX_V];
void add_edge(int from,int to,ll cap){
  G[from].push_back(edge(to,cap,G[to].size()));
  G[to].push_back(edge(from,0,G[from].size()-1));
}
// sツつゥツづァツづ個催短ツ仰猟猟」ツづーツ仰づ淞づゥ
void bfs(int s){
  memset(level,-1,sizeof(level));
  queue<int> que;
  level[s]=0;
  que.push(s);
  while(!que.empty()){
    int v=que.front();que.pop();
    for(int i=0;i<G[v].size();i++){
      edge &e=G[v][i];
      if(e.cap>0&&level[e.to]<0){
	level[e.to]=level[v]+1;
	que.push(e.to);
      }
    }
  }
}
// ツ堕敖嘉パツスツづーdfsツづ探ツつキ
ll dfs(int v,int t,ll f){
  if(v==t)return f;
  for(int &i=iter[v];i<G[v].size();i++){
    edge &e=G[v][i];
    if(e.cap>0&&level[v]<level[e.to]){
      ll d=dfs(e.to,t,min(f,e.cap));
      if(d>0){
	e.cap-=d;
	G[e.to][e.rev].cap+=d;
	return d;
      }
    }
  }
  return 0;
}
// sツつゥツづァtツづ鳴づ個催妥・ツ猟ャツづーツ仰づ淞づゥ
ll max_flow(int s,int t){
  ll flow=0;
  while(1){
    bfs(s);
    if(level[t]<0)return flow;
    memset(iter,0,sizeof(iter));
    ll f;
    while((f=dfs(s,t,INF))>0)flow+=f;
  }
}

int main(){
  while(cin>>H>>W>>C>>M>>Nw>>Nc>>Nm
	&&!(H<0&&W<0&&C<0&&M<0&&Nw<0&&Nc<0&&Nm<0)){
    const int s=1999;
    const int g=2000;
    const int nwNum=1998;
    const int nwNum2=1995;
    const int ncNum=1997;
    const int ncNum2=1994;
    const int nmNum=1996;
    
    for(int i=0;i<MAX_V;i++)G[i].clear();
    // ツゴツーツδ仰づ鳴古シツつゥツつ、ツ陛環δ仰ーツト
    add_edge(nwNum,nwNum2,Nw);
    //add_edge(nwNum2,ncNum,100);
    add_edge(ncNum,ncNum2,Nc);
    //add_edge(ncNum2,nmNum,100);
    add_edge(nmNum,g,Nm);
    
    for(int i=0;i<H;i++){
      add_edge(s,i,1);
      add_edge(i,nwNum,1);
    }
    for(int i=0;i<W;i++){
      add_edge(H+i,H+W+i,1);
      add_edge(H+W+i,ncNum,1);
      int num;
      cin>>num;
      while(num--){
	int t;
	cin>>t;
	add_edge(t-1,H+i,1);
      }
    }
    for(int i=0;i<C;i++){
      add_edge(nwNum2,H+2*W+i,100);
      add_edge(H+2*W+i,H+2*W+C+i,1);
      add_edge(H+2*W+C+i,nmNum,1);
      int num;
      cin>>num;
      while(num--){
	int t;
	cin>>t;
	add_edge(t-1+H+W,H+2*W+i,1);
      }
    }
    for(int i=0;i<M;i++){
      add_edge(ncNum2,H+2*W+2*C+i,100);
      add_edge(H+2*W+2*C+i,g,1);
      int num;
      cin>>num;
      while(num--){
	int t;
	cin>>t;
	add_edge(t-1+H+2*W+C,H+2*W+2*C+i,1);
      }
    }
    ll res=max_flow(s,g);
    cout<<res<<endl;
  }
  return 0;
}