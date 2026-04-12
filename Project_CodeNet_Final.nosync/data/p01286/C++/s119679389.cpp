#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cassert>
#include<climits>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<string>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define IINF (INT_MAX)
#define MAX 50*50
#define MAX_V 50*50

using namespace std;

//

struct edge{
  int to,cap,rev;
  edge(int to=IINF,int cap=IINF,int rev=IINF):to(to),cap(cap),rev(rev){}
};
 
vector<edge> G[MAX_V];
bool used[MAX_V];
 
void add_edge(int from,int to,int cap){
  G[from].push_back(edge(to,cap,G[to].size()));
  G[to].push_back(edge(from,0,(int)G[from].size()-1));
}
 
int dfs(int v,int t,int f){
  if(v == t)return f;
  used[v] = true;
  for(int i=0;i<G[v].size();i++){
    edge &e = G[v][i];
    if(!used[e.to] && e.cap > 0){
      int d = dfs(e.to,t,min(f,e.cap));
      if(d > 0){
	e.cap -= d;
	G[e.to][e.rev].cap += d;
	return d;
      }
    }
  }
  return 0;
}
 
int max_flow(int s,int t){
  int flow = 0;
  for(;;){
    memset(used,0,sizeof(used));
    int f = dfs(s,t,IINF);
    if(f == 0)return flow;
    flow += f;
  }
}

//

int counter[4];// H W C M
int csum[4];
int N[3]; // Nw Nc Nm
int limit[3][MAX];
int input_buf[3][MAX][MAX];
int Grave[3][2];
int V;

inline bool first_input(){
  bool fin = true;
  rep(i,4){
    cin >> counter[i];
    if(i == 0)csum[i] = counter[i];
    else      csum[i] = 2*counter[i] + csum[i-1];
    if( counter[i] >= 0 )fin = false;
  }
  rep(i,3){
    cin >> N[i];
    if( counter[i] >= 0 )fin = false;
  }
  return !fin;
}

int main(){
  while(first_input()){
    rep(i,3){
      rep(j,counter[i+1]){
	cin >> limit[i][j];
	rep(k,limit[i][j]){
	  cin >> input_buf[i][j][k];
	  input_buf[i][j][k]--;
	}
      }
    }

    int source = csum[3],sink = source+1;
    Grave[0][0] = sink+1       , Grave[0][1] = Grave[0][0]+1;
    Grave[1][0] = Grave[0][1]+1, Grave[1][1] = Grave[1][0]+1;
    Grave[2][0] = Grave[1][1]+1, Grave[2][1] = Grave[2][0]+1;

    V = Grave[2][1]+1;
    rep(i,V)G[i].clear();

    //1テ、ツコツコテ」ツ?ョテ、ツコツコテ」ツ?ッ1テ・ツ崢榲」ツ?セテ」ツ?ァテ」ツ?療」ツ?凝」ツ?、テ」ツ?凝」ツ?暗」ツ?ェテ」ツ??」ツつ暗」ツ??」ツ?ォテ」ツ?凖」ツつ凝」ツ?ョテ・ツソツ佚」ツつ古」ツ?ヲテ」ツ??( テ・ツ青古」ツ?佚、ツコツコテ」ツつ津、ツスツ陛・ツコツヲテ」ツつづ、ツスツソテァツ板ィテ」ツ?療」ツ?ヲテ」ツ??」ツ?淌」ツ?淌」ツつ仝A )
    rep(i,3)rep(j,counter[i+1])add_edge(csum[i]+j,csum[i]+j+counter[i+1],1);

    rep(i,counter[0])add_edge(source,i,1);
    rep(i,counter[3])add_edge(csum[2]+i+counter[3],sink,1);
    rep(i,3){
      rep(j,counter[i+1]){
	rep(k,limit[i][j]){
	  add_edge(input_buf[i][j][k]+((i-1)>=0?csum[i-1]:0)+((i)?counter[i]:0),csum[i]+j,1);
	}
      }
    }

    rep(k,2){
      int coef = ((k==0)?0:counter[k]);
      rep(i,counter[k])add_edge(((k-1)>=0?csum[k-1]:0)+i+coef,Grave[k][0],1);
      add_edge(Grave[k][0],Grave[k][1],N[k]);
      rep(i,counter[k+2])add_edge(Grave[k][1],csum[k+1]+i,1);
    }

    rep(i,counter[2])add_edge(csum[1]+i+counter[2],Grave[2][0],1);
    add_edge(Grave[2][0],sink,N[2]);

    int tmp;
    cout << (tmp=max_flow(source,sink)) << endl;
    assert(0 <= tmp && tmp <= counter[0] );

  }
  return 0;
}