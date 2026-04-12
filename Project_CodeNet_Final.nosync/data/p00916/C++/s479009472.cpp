#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
bool in_range(int x, int r){
  return (x >= 0 && x < r);
}

void dfs(vector< vector<long long int> > &B, long long int c, int x, int y){
  int w = B.size(), h = B[0].size();
  B[x][y] = -1;
  for(int i = 0; i < 4; ++i){
    int x_ = x + dx[i], y_ = y + dy[i];
    if(in_range(x_,w) && in_range(y_,h) && B[x_][y_] == c){
      dfs(B,c,x_,y_);
    }
  }
}

int main(){
  int n;
  while(cin >> n, n){
    set<int> X, Y;
    vector<int> L(n), T(n), R(n), B(n);
    for(int i = 0; i < n; ++i){
      cin >> L[i] >> T[i] >> R[i] >> B[i];
      X.insert(L[i]);
      X.insert(R[i]);
      Y.insert(T[i]);
      Y.insert(B[i]);
    }
    X.insert(-1);
    X.insert(10000000);
    Y.insert(-1);
    Y.insert(10000000);
    map<int,int> M_x, M_y;
    int id = 0;
    for(auto itr = X.begin(); itr != X.end(); ++itr){
      M_x[*itr] = id;
      ++id;
    }
    id = 0;
    for(auto itr = Y.begin(); itr != Y.end(); ++itr){
      M_y[*itr] = id;
      ++id;
    }
    
    int w = X.size(), h = Y.size();
    vector< vector<long long int> > G(w, vector<long long int>(h,0));
    
    for(int i = 0; i < n; ++i){
      int l = L[i], t = T[i], r = R[i], b = B[i];
      for(int j = M_x[l]; j < M_x[r]; ++j)
        for(int k = M_y[b]; k < M_y[t]; ++k)
          G[j][k] |= (1LL<<i);
    }
    /*
    for(int i = h-1; i >= 0; --i){
      for(int j = 0; j < w; ++j){
        cout << G[j][i] << " | ";
      }cout << endl;
    }
    */
    long long int ans = 0;
    for(int i = 0; i < w; ++i){
      for(int j = 0; j < h; ++j){
        if(G[i][j] != -1){
          ++ans;
          dfs(G,G[i][j],i,j);
        }
      }
    }

    cout << ans << endl;
  }
  return 0;
}

