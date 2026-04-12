//brute force solve
//choose arbitary one or two edge
//then check connectivity O(V^3)?
#include<iostream>
#include<cstdio>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(C) (C).begin(),(C).end()
#define fi first
#define se second

const int N = 1000;
struct Edge{
  int from,to,cost;
};

class DisjointSet{
public:
  int rank[N],p[N];
  
  DisjointSet(){}
  DisjointSet(int size){
  }
  void make_set(int x){
    p[x]=x;
    rank[x]=0;
  }
  void merge(int x,int y){
    link(find_set(x),find_set(y));
  }
  void link(int x,int y){
    if (rank[x]>rank[y]){
      p[y]=x;
    }else {
      p[x]=y;
      if ( rank[x] ==rank[y])rank[y]+=1;
    }
  }
  int find_set(int x){
    if (x != p[x])p[x]=find_set(p[x]);
    return p[x];
  }
};



bool adj[N][N];
vector<Edge> edge[N];
vector<Edge> all;
DisjointSet dj;

bool isdisjoint(int n){
  rep(i,n)dj.make_set(i);
  rep(i,n){
    rep(j,(int)edge[i].size()){
      if (adj[i][edge[i][j].to]){
	dj.merge(i,edge[i][j].to);
      }
    }
  }
  int tmp=dj.find_set(0);
  rep(i,n)if (tmp != dj.find_set(i))return true;
  return false;
}

int solve(int n){
  int ret=INT_MAX;
  if (isdisjoint(n))return 0;
  rep(i,n){
    rep(j,(int)edge[i].size()){
      adj[i][edge[i][j].to]=false;
      if (isdisjoint(n))ret=min(ret,edge[i][j].cost);
      adj[i][edge[i][j].to]=true;
    }
  }
  rep(i,(int)all.size()){
    adj[all[i].from][all[i].to]=false;
    REP(j,i+1,(int)all.size()){
      adj[all[j].from][all[j].to]=false;
      if (isdisjoint(n)){
	ret=min(ret,all[i].cost+all[j].cost);
      }
      adj[all[j].from][all[j].to]=true;
    }
    adj[all[i].from][all[i].to]=true;
  }
  //cout <<"tpm " << ret << endl;
  return ret;
}

main(){
  int n,m;
  while(cin>>n>>m && n){
    rep(i,n){
      edge[i].clear();
      rep(j,n){
	adj[i][j]=false;
      }
    }
    all.clear();
    
    int ans=0;
    rep(i,m){
      int f,t,c;
      cin>>f>>t>>c;

      if (c <= 0){//elminate negative edge (also negative seledge)
	ans+=c;//c<0
      }else if (f == t){//ignore self edge of positive cost
      }else {
	edge[f].push_back((Edge){f,t,c});
	all.push_back((Edge){f,t,c});
	adj[f][t]=true;
      }
    }
    int sum=solve(n);
    cout << ans+sum << endl;
  }
  return false;
}