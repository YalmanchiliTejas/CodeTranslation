#include <iostream>
#include <vector>
#include <map>
using namespace std;
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1}, INF = 1e9;

bool in_range(int a, int b){
  return a >= 0 && a < b;
}

int main(){
  int R, C, M;
  cin >> R >> C >> M;
  vector<string> S(R);
  for(int i = 0; i < R; ++i) cin >> S[i];
  map<int,int> mp;
  int n = 0;
  for(int i = 0; i < R; ++i){
    for(int j = 0; j < C; ++j){
      if(S[i][j] == '.'){
        mp[i*C+j] = n;
        ++n;
      }
    }
  }
  vector< vector<int> > D(n, vector<int>(n,INF));
  for(int x = 0; x < R; ++x){
    for(int y = 0; y < C; ++y){
      if(S[x][y] == '.'){
        for(int j = 0; j < 4; ++j){
          int x_ = x + dx[j], y_ = y + dy[j], i = mp[x*C+y];
          if(in_range(x_,R) && in_range(y_,C) && S[x_][y_] == '.'){
            int v = mp[x_*C+y_];
            D[i][v] = 1;
          }
        }
      }
    }
  }
  for(int i = 0; i < n; ++i) D[i][i] = 0;
  for(int k = 0; k < n; ++k){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        D[i][j] = min(D[i][j],D[i][k] + D[k][j]);
      }
    }
  }

  vector< vector<int> > G(n, vector<int>(n,-1));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(i == j) continue;
      for(int k = 0; k < n; ++k){
        if(D[i][k] == 1 && D[i][j] == D[i][k] + D[k][j]){
          G[i][j] = k;
          break;
        }
      }
    }
  }
  

  vector<int> P(n), OnOff = P;
  int t;
  for(int i = 0; i < R; ++i){
    for(int j = 0; j < C; ++j){
      cin >> t;
      if(t > 0) P[mp[i*C+j]] = t;
    }
  }
  for(int i = 0; i < R; ++i){
    for(int j = 0; j < C; ++j){
      cin >> t;
      if(t > 0) OnOff[mp[i*C+j]] = t;
    }
  }
  for(int i = 0; i < R; ++i){
    for(int j = 0; j < C; ++j){
      cin >> t;
      if(t > 0) OnOff[mp[i*C+j]] += t;
    }
  }
  int x, y;
  cin >> x >> y;
  vector<int> T(n,-1);
  T[mp[x*C+y]] = 0;
  t = 0;
  int v = mp[x*C+y];
  long long int ans = OnOff[v];
  for(int i = 1; i < M; ++i){
    cin >> x >> y;
    int v_ = mp[x*C+y];
    while(v != v_){
      v = G[v][v_];
      ++t;
      if(T[v] < 0){
        T[v] = t;
        ans += OnOff[v];
      }else{
        ans += min((long long int)OnOff[v], (long long int)(P[v]*(t-T[v])));
        T[v] = t;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

