#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;

int main(){
  int N,M; cin >> N >> M;
  bool g[N][N];
  int p[N];
  rep(i,N) p[i] = i;
  rep(i,N)rep(j,N) g[i][j] = false;
  for(int i = 0; i < M; i++){
    int a,b; cin >> a >> b;
    a--; b--;
    g[a][b] = g[b][a] = true;
  }
  int ans = 0;
  do{
    bool flg = true;
    if(p[0] != 0) break;
    for(int i = 0; i < N-1; i++){
      if(!g[p[i]][p[i+1]]) flg = false;
    }
    if(flg) ans++;
  }while(next_permutation(p, p+N));
  cout << ans << endl;
  return 0;
}
