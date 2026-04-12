#include<bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < int(n); i++)
#define repeat(i, j, n) for(int i = int(j); i < int(n); i++)
#define all(v) begin(v), end(v)

using namespace std;

map<int, int> compress(vector<int> X) {
  map<int, int> res;
  sort(all(X));
  int cnt = 0;
  for(int x : X) {
    for(int i : {-1, 0, 1}) 
      if(not res.count(x + i)) res[x + i] = cnt++;
  }
  return res;
}

int main() {
  while(true) {
    int N; cin >> N;
    if(N == 0) break;

    vector<int> L(N), T(N), R(N), B(N);
    vector<int> X, Y;
    rep(i, N) {
      cin >> L[i] >> T[i] >> R[i] >> B[i];
      L[i] *= 2;
      T[i] *= 2;
      R[i] *= 2;
      B[i] *= 2;
    }
    L.push_back(-2);
    R.push_back(1e6 * 2 + 2);
    B.push_back(-2);
    T.push_back(1e6 * 2 + 2);
    N++;
    rep(i, N) {
      X.push_back(L[i]);
      X.push_back(R[i]);
      Y.push_back(T[i]);
      Y.push_back(B[i]);
    }
    auto map_x = compress(X);
    auto map_y = compress(Y);
    rep(i, N) {
      L[i] = map_x[L[i]];
      R[i] = map_x[R[i]];
      T[i] = map_y[T[i]];
      B[i] = map_y[B[i]];
    }

    vector<vector<int>> G(map_y.size(), vector<int>(map_x.size()));

    rep(i, N) {      
      repeat(x, L[i], R[i] + 1) G[B[i]][x] = -1;
      repeat(x, L[i], R[i] + 1) G[T[i]][x] = -1;
      repeat(y, B[i], T[i] + 1) G[y][L[i]] = -1;
      repeat(y, B[i], T[i] + 1) G[y][R[i]] = -1;
    }

    //rep(i, G.size()) {
    //rep(j, G[i].size()) cerr << G[i][j] << " ";
    //cerr << endl;
    //}
    const int dy[] = {0, 1, 0, -1};
    const int dx[] = {1, 0, -1, 0};
    function<void(int, int, int)> fill = [&] (int y, int x, int c) {
      G[y][x] = c;
      rep(i, 4) {
	int ny = y + dy[i];
	int nx = x + dx[i];
	if(0 <= ny and ny < G.size() and 0 <= nx and nx <= G[ny].size()) {
	  if(G[ny][nx] == 0) fill(ny, nx, c);
	}
      }
    };
    
    int cnt = 0;
    rep(i, G.size()) {
      rep(j, G[i].size()) if(G[i][j] == 0) fill(i, j, ++cnt);
    }

    cout << cnt - 1 << endl;
    
  }
  return 0;
}

