#include<bits/stdc++.h>
using namespace std;
int INF = 1e8;

struct edge{ int to,cap,rev; };
vector<edge> G[1000];
bool used[1000];

void add_edge(int from,int to,int cap){
  if(cap==0)return;
  G[from].push_back((edge){to,cap,(int)G[to].size()});
  G[to].push_back((edge){from,0,(int)G[from].size()-1});
}

int dfs(int v,int t,int f){
  if(v == t) return f;
  used[v] = true;
  for(int i = 0 ; i < (int)G[v].size() ; i++){
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
    memset(used,false,sizeof(used));
    int f = dfs(s,t,INF);
    if(f == 0) return flow;
    flow += f;
  }
}

int A,B,C,D,BX,CX,DX;
int AB[500][500];
int BC[500][500];
int CD[500][500];

int main(){
  while(1){
    cin>>A>>B>>C>>D>>BX>>CX>>DX;
    if(A<0||B<0||C<0||D<0||BX<0||CX<0||DX<0)break;
    for(int i=0;i<1000;i++)G[i].clear();

    assert( A<=50 && B<=50 && C<=50 && D<=50 );
    assert( BX<=50 && CX<=50 && DX<=50 );
    
    memset(AB,0,sizeof(AB));
    memset(BC,0,sizeof(BC));
    memset(CD,0,sizeof(CD));
    
    for(int i=0;i<B;i++){
      int k,l;
      cin>>k;
      for(int j=0;j<k;j++){
        cin>>l;
        assert(1<=l && l<=A);
        l--;
        AB[l][i]=1;
      }
    }
    
    for(int i=0;i<C;i++){
      int k,l;
      cin>>k;
      for(int j=0;j<k;j++){
        cin>>l;
        assert(1<=l && l<=B);
        l--;
        BC[l][i]=1;
      }
    }
        
    for(int i=0;i<D;i++){
      int k,l;
      cin>>k;
      for(int j=0;j<k;j++){
        cin>>l;
        assert(1<=l && l<=C);
        l--;
        CD[l][i]=1;
      }
    }
    
    int si=A+B+C+D+BX+CX+DX;
    int ti=si+1;
    
    for(int i=0;i<A;i++){
      add_edge(si,i,1);
    }

    for(int i=0;i<A;i++){
      for(int j=0;j<B+BX;j++){
        int cap=AB[i][j];
        if(j>=B)cap=1;
        add_edge(i,A+j,cap);
      }
    }

    for(int i=0;i<B+BX;i++){
      add_edge(A+i,ti+A+i,1);
      for(int j=0;j<C+CX;j++){
        int cap=BC[i][j];
        if(i>=B||j>=C)cap=1;
        if(i>=B&&j>=C)cap=0;
        add_edge(ti+A+i,A+B+BX+j,cap);
      }
    }

    for(int i=0;i<C+CX;i++){
      add_edge(A+B+BX+i,ti+A+B+BX+i,1);
      for(int j=0;j<D+DX;j++){
        int cap=CD[i][j];
        if(i>=C||j>=D)cap=1;
        if(i>=C&&j>=D)cap=0;
        add_edge(ti+A+B+BX+i,A+B+BX+C+CX+j,cap);
      }
    }

    for(int i=0;i<D+DX;i++){
      add_edge(A+B+BX+C+CX+i,ti,1);
    }
    cout<< max_flow(si,ti) <<endl;
  }
  return 0;
}