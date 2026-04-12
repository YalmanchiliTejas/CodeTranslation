#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge{
  int to,cap,rev;
};

vector<edge> G[307];
bool used[307];

void add_edge(int from,int to,int cap){
  G[from].push_back({to,cap,(int)G[to].size()});
  G[to].push_back({from,0,(int)G[from].size()-1});
}

int dfs(int v,int t,int f){
  if(v==t)return f;
  used[v]=true;
  for(int i=0;i<G[v].size();i++){
    edge &e=G[v][i];
    if(!used[e.to]&&e.cap>0){
      int d=dfs(e.to,t,min(f,e.cap));
      if(d>0){
	//	cout<<v<<' '<<e.to<<endl;
	e.cap-=d;
	G[e.to][e.rev].cap+=d;
	return d;
      }
    }
  }
  return 0;
}

int max_flow(int s,int t){
  int flow=0;
  for(;;){
    fill(begin(used),end(used),false);
    int f=dfs(s,t,1<<29);
    if(f==0)return flow;
    flow+=f;
  }
}
      
int main(){
  for(int H,W,C,M,NW,NC,NM;cin>>H>>W>>C>>M>>NW>>NC>>NM,H>=0;){
    for(auto &e:G){
      e.clear();
    }
    int s=H+2*W+2*C+M;
    for(int i=0;i<H;i++){
      add_edge(s,i,1);
      add_edge(i,s+1,1);
    }
    for(int i=0;i<W;i++){
      add_edge(H+i,H+W+i,1);
      add_edge(H+W+i,s+3,1);
      int n;
      cin>>n;
      while(n--){
	int id;
	cin>>id;
	add_edge(id-1,H+i,1);
      }
    }
    add_edge(s+1,s+2,NW);
    for(int i=0;i<C;i++){
      int o=H+2*W;
      add_edge(o+i,o+C+i,1);
      add_edge(s+2,o+i,1);
      add_edge(o+C+i,s+5,1);
      int n;
      cin>>n;
      while(n--){
	int id;
	cin>>id;
	add_edge(H+W+id-1,o+i,1);
      }
    }
    add_edge(s+3,s+4,NC);
    for(int i=0;i<M;i++){
      add_edge(s+4,H+2*W+2*C+i,1);
      add_edge(H+2*W+2*C+i,s+6,1);
      int n;
      cin>>n;
      while(n--){
	int id;
	cin>>id;
	add_edge(H+2*W+C+id-1,H+2*W+2*C+i,1);
      }
    }
    add_edge(s+5,s+6,NM);
    cout<<max_flow(s,s+6)<<endl;
  }
}