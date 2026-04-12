#include<cstdio>
#include<queue>
#include<utility>
#include<cstring>
#include<stack>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<map>
#define MAX_N 100001
#define INF_INT 2147483647
#define INF_LL 9223372036854775807
#define REP(i,n) for(int i=0;i<(int)(n);i++)
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
bool cmp_P(const P &a,const P &b){
  return a.second < b.second;
}
int main()
{
  int N,H,W,f=1;
  bool visited[100][100];
  char a[100][100];
  cin >> H >> W;
  REP(i,H){
    cin >> a[i];
  }
  REP(i,100)REP(j,100)visited[i][j] = false;
  queue<P> que;
  int c = 0;
  que.push(P(0,0));
  while(!que.empty()){
    c = 0;
    P p = que.front();que.pop();
    
    if(visited[p.first][p.second])
      continue;
    visited[p.first][p.second] = true;
    
    REP(i,4){
      if(p.first+dx[i] < W && p.second+dy[i] < H && p.first+dx[i] >= 0 && p.second >= 0)
        if(a[p.second+dy[i]][p.first+dx[i]] == '#'){
          if(i < 2){
            que.push(P(p.first+dx[i],p.second+dy[i]));
          }else if(!(visited[p.first+dx[i]][p.second+dy[i]])){
            f = 0;
          }
          if(!(visited[p.first+dx[i]][p.second+dy[i]]))
            c++;
        }
      if(c >= 2)
        f=0;
    }
    
  }

  
  
  if(f && visited[W-1][H-1])
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
}

