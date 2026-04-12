#include<bits/stdc++.h>
using namespace std;
int INF = 1e8;
struct edge{ int to,cap,rev; };
vector<edge> G[5000];
bool used[5000];

void init_edge(){
  for(int i=0;i<5000;i++){
    G[i].clear();
  }
}

void add_edge(int from,int to,int cap){
  G[from].push_back((edge){to,cap,(int)G[to].size()});
  G[to].push_back((edge){from,0,(int)G[from].size()-1});
}

int dfs(int v,int t,int f){
  if(v==t)return f;
  used[v]=true;
  for(int i=0;i<(int)G[v].size();i++){
    edge &e=G[v][i];
    if(!used[e.to]&&e.cap>0){
      int d=dfs(e.to,t,min(f,e.cap));
      if(d>0){
        e.cap-=d;
        G[e.to][e.rev].cap+=d;
        return d;
      }
    }
  }
  return 0;
}
int max_flow(int s,int t){
  if(s==t)return INF;
  
  int flow=0;
  while(1){
    memset(used,0,sizeof(used));
    int f=dfs(s,t,INF);
    if(f==0)break;
    flow+=f;
  }

  return flow;
}


int N,M;
char c[100][100];
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};

int calc(int y,int x){
  return y*M+x;
}

void make_graph(){
  init_edge();  
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      int flg=1;
      if( i==0 && j== 0)flg=2;
      if( i==0 && j==M-1)flg=2;
      if( i==N-1 && j==0)flg=2;
      if( i==N-1 && j==M-1)flg=2;
      add_edge( calc(i,j) , calc(i,j) + N*M , flg);
      
      for(int dir=0;dir<4;dir++){
        int ni=i+di[dir];
        int nj=j+dj[dir];
        if(ni<0 || nj<0 || ni>=N || nj>=M)continue;
        if(c[ni][nj]=='#')continue;
        if(c[i][j]=='#')continue;
        
        add_edge( calc(i,j)+N*M , calc(ni,nj) , 1);
      }
    }
  }
}

int main(){
  while(1){
    cin>>N>>M;
    if(N==0&&M==0)break;
    
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        cin>>c[i][j];
      }
    }

    make_graph();
    if( max_flow( calc(0,0) , calc(N-1,M-1)+N*M ) < 2){
      cout<<"NO"<<endl;
      continue;
    }


    
    make_graph();
    if( max_flow( calc(0,M-1) , calc(N-1,0)+N*M ) < 2){
      cout<<"NO"<<endl;
      continue;
    }

    cout<<"YES"<<endl;
  }

  return 0;
}