#include <bits/stdc++.h>
#define int long long
#define MAX_V 1000
#define N MAX_V
using namespace std;
const int INF = 1LL<<55;
const int mod = (1e9)+7;
const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}

/*?????§?????¢?????´?????????(Ford_Fulerson????????¨)???O(F|E|)*/

//????????¨????§???????(???????????????????????????)
struct edge{int to, cap, rev;};

vector<edge> G[MAX_V]; //??°???????????£??\?????????
bool used[MAX_V];      //DFS??§?????§??????????????????????????°

//from??????to??????????????????cap???????????°?????????????????????
void add_edge(int from,int to,int cap=1){
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

signed main(){

  int cnt = 0;

  while(1){
    cnt ++;
    int H, W, C, M, N_W, N_C, N_M;
    cin >>H>>W>>C>>M>>N_W>> N_C>>N_M;
    if(H==-1) return 0;
    for(int i=0;i<N;i++)G[i].clear();
    
    const int S = N-1, T = S-1;
    const int NW = H+W+C+M, NC = NW+1, NM = NC+1;
    const int of = 500; //ofset
    
    add_edge(NW,of+NW,N_W);
    add_edge(NC,of+NC,N_C);
    add_edge(NM,of+NM,N_M);
    for(int i=0;i<H;i++) add_edge(i,of+i); //hero
    for(int i=0;i<W;i++) add_edge(H+i,of+H+i); // warriror
    for(int i=0;i<C;i++) add_edge(H+W+i,of+H+W+i); // Cleric
    for(int i=0;i<M;i++) add_edge(H+W+C+i,of+H+W+C+i); //Mage
  
    
    for(int i=0;i<H;i++) add_edge(S,i); // S -> Hero

    
    for(int i=0;i<H;i++) add_edge(of+i,NW); // Hero -> no warrior
    for(int i=0,k;i<W;i++){
      cin>>k;
      for(int j=0,a;j<k;j++) {
        cin>>a; a--;
        add_edge(of+a,H+i); // hero -> warrior
      }
    }

    
    for(int i=0;i<W;i++) add_edge(of+H+i,NC); // warrior -> no cleric
    for(int i=0;i<C;i++) add_edge(of+NW,H+W+i); // no warrior -> cleric
    for(int i=0,k;i<C;i++){
      cin>>k;
      for(int j=0,a;j<k;j++){
        cin>>a,a--;
        add_edge(of+H+a,H+W+i); // warrior -> cleric 
      }
    }

    
    for(int i=0;i<C;i++) add_edge(of+H+W+i,NM); // cleric -> no mage
    for(int i=0;i<M;i++) add_edge(of+NC,H+W+C+i); // no cleric -> mage   
    for(int i=0,k;i<M;i++){
      cin>>k;
      for(int j=0,a;j<k;j++){
        cin>>a;a--;
        add_edge(of+H+W+a,H+W+C+i); // cleric -> mage
      }
    }

    add_edge(of+NM,T,N_M);//no mage -> T 
    for(int i=0;i<M;i++) add_edge(of+H+W+C+i,T); // mage -> T
    cout<<max_flow(S,T)<<endl;
  }

  return 0;
}