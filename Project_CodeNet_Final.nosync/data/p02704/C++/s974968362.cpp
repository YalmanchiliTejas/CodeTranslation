#include <bits/stdc++.h>

using namespace std;

int h, w;
vector< int > opy, opx;
vector< uint64_t > y, x, by, bx;
vector< vector< uint64_t > > ans, b;

bool solvebit() {
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) b[i][j] = -1;
  vector< int > ry, rx;
  for(int i = 0; i < h; i++) {
    if(opy[i] == by[i]) for(int j = 0; j < w; j++) b[i][j] = by[i];
    else ry.push_back(i);
  }
  for(int i = 0; i < w; i++) {
    if(opx[i] == bx[i]) {
      for(int j = 0; j < h; j++) {
        if(b[j][i] == !bx[i]) return false;
        b[j][i] = bx[i];
      }
    } else rx.push_back(i);
  }
  int rh = ry.size(), rw = rx.size();
  if(min(rh, rw) >= 2) {
    if(rw <= rh) {
      for(int i = 0; i < rh; i++) {
        b[ry[i]][rx[i % rw]] = 1;
        b[ry[i]][rx[(i + 1) % rw]] = 0;
      }
    } else {
      for(int i = 0; i < rw; i++) {
        b[ry[i % rh]][rx[i]] = 1;
        b[ry[(i + 1) % rh]][rx[i]] = 0;
      }
    }
  } else if(min(rh, rw) == 1) {
    if(rw == 1) {
      for(int i = 0; i < rh; i++) {
        bool g = false;
        for(int j = 0; j < w; j++) if(b[ry[i]][j] == by[ry[i]]) g = true;
        if(!g) b[ry[i]][rx[0]] = by[ry[i]];
      }
      bool g = false;
      for(int i = 0; i < h; i++) {
        if(b[i][rx[0]] == bx[rx[0]]) {
          g = true;
          break;
        }
        if(b[i][rx[0]] == -1) {
          b[i][rx[0]] = bx[rx[0]];
          g = true;
          break;
        }
      }
      if(!g) return false;
    } else {
      for(int i = 0; i < rw; i++) {
        bool g = false;
        for(int j = 0; j < h; j++) if(b[j][rx[i]] == bx[rx[i]]) g = true;
        if(!g) b[ry[0]][rx[i]] = bx[rx[i]];
      }
      bool g = false;
      for(int i = 0; i < w; i++) {
        if(b[ry[0]][i] == by[ry[0]]) {
          g = true;
          break;
        }
        if(b[ry[0]][i] == -1) {
          b[ry[0]][i] = by[ry[0]];
          g = true;
          break;
        }
      }
      if(!g) return false;
    }
  } else if(min(rh, rw) == 0) {
    for(int i = 0; i < h; i++) {
      int beetand = b[i][0], beetor = b[i][0];
      for(int j = 1; j < w; j++) {
        beetand &= b[i][j];
        beetor |= b[i][j];
      }
      if((opy[i] && beetand != by[i]) || (!opy[i] && beetor != by[i])) return false;
    }
    for(int i = 0; i < w; i++) {
      int beetand = b[0][i], beetor = b[0][i];
      for(int j = 1; j < h; j++) {
        beetand &= b[j][i];
        beetor |= b[j][i];
      }
      if((opx[i] && beetand != bx[i]) || (!opx[i] && beetor != bx[i])) return false;
    }
  }
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(b[i][j] == -1) b[i][j] = 0;
  return true;
}

int main() {
  string op;
  int n;
  cin >> n;
  h = n, w = n;
  opy.resize(h);
  opx.resize(w);
  y.resize(h);
  by.resize(h);
  x.resize(w);
  bx.resize(w);
  ans.resize(h, vector< uint64_t >(w));
  b.resize(h, vector< uint64_t >(w));
  for(int i = 0; i < h; i++) {
    cin >> opy[i];
    opy[i] ^= 1;
  }
  for(int i = 0; i < w; i++) {
    cin >> opx[i];
    opx[i] ^= 1;
  }
  for(int i = 0; i < h; i++) {
    cin >> y[i];
  }
  for(int i = 0; i < w; i++) {
    cin >> x[i];
  }
  bool f = true;
  for(int k = 0; k < 64; k++) {
    for(int i = 0; i < h; i++) by[i] = (y[i] & (((uint64_t) 1) << k)) != 0;
    for(int i = 0; i < w; i++) bx[i] = (x[i] & (((uint64_t) 1) << k)) != 0;
    if(!solvebit()) f = false;
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) ans[i][j] += b[i][j] * (((uint64_t) 1) << k);
  }
  if(!f) {
    cout << -1 << endl;
    return 0;
  }
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(j) cout << " ";
      cout << ans[i][j];
    }
    cout << endl;
  }
}
