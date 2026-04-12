#include <bits/stdc++.h>
#define INF 1e9
#define MAX_V 10000
using namespace std;

/*?????§?????¢?????´?????????(Ford_Fulerson????????¨)???O(F|E|)*/

//????????¨????§???????(???????????????????????????)
struct edge{int to, cap, rev;};

vector<edge> G[MAX_V]; //??°???????????£??\?????????
bool used[MAX_V];      //DFS??§?????§??????????????????????????°

void init(){
  for(int i=0;i<MAX_V;i++) G[i].clear();
}

//from??????to??????????????????cap???????????°?????????????????????
void add_edge(int from,int to,int cap){
  G[from].push_back((edge){to,cap,(int)G[to].size()});
  G[to].push_back((edge){from,0,(int)G[from].size()-1});  
}

//?¢?????????????DFS??§??¢???
int dfs(int v,int t,int f){
  if(v == t)return f;
  used[v]=true;
  for(int i=0; i<G[v].size() ;i++){
    edge &e = G[v][i];
    if(!used[e.to] && e.cap > 0){
      int d = dfs(e.to ,t , min(f,e.cap));
      if(d > 0){
	e.cap -= d;
	G[e.to][e.rev].cap += d;
	return d;
      }
    }
  }
  return 0;
}

//s??????t???????????§???????±???????
int max_flow(int s,int t){
  int flow = 0;
  for(;;){
    memset(used,0,sizeof(used));
    int f = dfs(s, t, INF);
    if(f == 0)return flow;
    flow += f;
  }
}

int main(){
  
  int H, W, C, M, Nw, Nc, Nm;
  
  while(1){
    
    cin>>H>>W>>C>>M>>Nw>>Nc>>Nm;
    if(H==-1) break;

    init();
    
    int s=0;
    int Hws=(H+W+C+M)*2+1, Hwt=Hws+1;
    int Hcs=Hwt+1, Hct=Hcs+1;
    int Hms=Hct+1, Hmt=Hms+1;
    int t=Hmt+1;

    for(int i=1;i<=H;i++){
      add_edge(s,i*2-1,1);
      add_edge(i*2-1,i*2,1);
      add_edge(i*2,Hws,1);
    }
    
    for(int i=1;i<=W;i++){
      int n;
      cin>>n;
      add_edge((H+i)*2-1,(H+i)*2,1);
      add_edge((H+i)*2,Hcs,1);
      for(int j=0;j<n;j++){
	int a;
	cin>>a;
	add_edge(a*2,(H+i)*2-1,1);
      }
    }
    
    for(int i=1;i<=C;i++){
      int n;
      cin>>n;
      add_edge(Hwt,(H+W+i)*2-1,INF);
      add_edge((H+W+i)*2-1,(H+W+i)*2,1);
      add_edge((H+W+i)*2,Hms,1);
      for(int j=0;j<n;j++){
	int a;
	cin>>a;
	add_edge((H+a)*2,(H+W+i)*2-1,1);
      }
    }
    
    for(int i=1;i<=M;i++){
      int n;
      cin>>n;
      add_edge(Hct,(H+W+C+i)*2-1,INF);
      add_edge((H+W+C+i)*2-1,(H+W+C+i)*2,1);
      add_edge((H+W+C+i)*2,t,1);
      for(int j=0;j<n;j++){
	int a;
	cin>>a;
	add_edge((H+W+a)*2,(H+W+C+i)*2-1,1);
      }
    }

    add_edge(Hws,Hwt,Nw);
    add_edge(Hcs,Hct,Nc);
    add_edge(Hms,Hmt,Nm);
    add_edge(Hmt,t,INF);
    
    cout<<max_flow(s, t)<<endl;
  }
  
  return 0;
}