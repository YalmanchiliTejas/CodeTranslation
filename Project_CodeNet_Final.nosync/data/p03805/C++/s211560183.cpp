using namespace std;
#include<bits/stdc++.h>
#define BEGIN ios_base::sync_with_stdio(0);cin.tie(0)
#define END return EXIT_SUCCESS
#define FOR(I,A,B) for((I)=(A);(I)<(B);(I)++)
#define REP(I,N) FOR(I,0,N)
#define UP(I,A,B) for((I)=(A);(I)<=(B);(I)++)
#define DW(I,A,B) for((I)=(A);(I)>=(B);(I)--)
#define IN(P) cin>>(P)
#define IN2(P1,P2) cin>>(P1)>>(P2)
#define IN3(P1,P2,P3) cin>>(P1)>>(P2)>>(P3)
#define INS(I,N,V) REP(I,N) cin>>V[I]
#define INS2(I,N,V1,V2) REP(I,N) cin>>V1[I]>>V2[I];
#define INS3(I,N,V1,V2,V3) REP(I,N) cin>>V1[I]>>V2[I]>>V3[I];
#define OUT(P) cout<<P<<endl
#define OUT2(P1,P2) cout<<P1<<" "<<P2<<endl
#define OUT3(P1,P2,P3) cout<<P1<<" "<<P2<<" "<<P3<<endl
#define OUTS(I,N,V) REP(I,N) cout<<V[i]<<endl
#define ALL(C) (C).begin(),(C).end()
#define RALL(C) (C).rbegin(),(C).rend()
#define mp make_pair
#define pb push_back
typedef unsigned long ul;
typedef unsigned int ui;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

long N,M,a,b,ans;
vector<vector<long> > G;
vector<bool> visited;

void dfs(long v){
  visited[v]=true;
  bool flag=true;
  for(long i=1;i<N;i++){
    if(!visited[i]){
      flag=false;
      break;
    }
  }
  if(flag){
    ans++;
    return;
  }
  for(long i=0;i<(long)G[v].size();i++){
    if(!visited[G[v][i]]){
      dfs(G[v][i]);
      visited[G[v][i]]=false;
    }
  }
}

inline void solve(){
  long i;
  IN2(N,M);
  G.resize(N);
  visited.resize(N);
  REP(i,M){
    IN2(a,b);
    G[--a].pb(--b);
    G[b].pb(a);
  }
  dfs(0);
  OUT(ans);
}

int main(int argc,char**argv){
  BEGIN;
  solve();
  END;
}
