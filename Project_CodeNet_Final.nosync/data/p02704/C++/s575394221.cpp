#include <bits/stdc++.h>
 
using namespace std;
 
void fail() {
  cout << -1 << endl;
  exit(0);
}
 
int main() {
  int N;
  cin >> N;
  string A[500], C[500];
  uint64_t B[500], D[500];
  int H = N, W = N;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if(x == 0) A[i] = "and";
    else A[i] = "or";
  }
 
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if(x == 0) C[i] = "and";
    else C[i] = "or";
  }
  for(int i = 0; i < N; i++) {
    cin >> B[i];
  }
  for(int i = 0; i < N; i++) {
    cin >> D[i];
  }
 
  uint64_t ans[500][500] = {{}};
  for(int i = 0; i < 64; i++) {
    vector< vector< int > > decide(H, vector< int >(W, -1));
    vector< pair< int, int > > latte, malta;
 
    for(int j = 0; j < H; j++) {
      if(A[j] == "and") {
        if((B[j] >> i) & 1) for(int k = 0; k < W; k++) decide[j][k] = 1;
        else latte.emplace_back(j, 0);
      } else {
        if((~B[j] >> i) & 1) for(int k = 0; k < W; k++) decide[j][k] = 0;
        else latte.emplace_back(j, 1);
      }
    }
    for(int j = 0; j < W; j++) {
      if(C[j] == "and") {
        if((D[j] >> i) & 1) {
          for(int k = 0; k < H; k++) if(decide[k][j] == 0) fail();
          for(int k = 0; k < H; k++) decide[k][j] = 1;
        } else malta.emplace_back(j, 0);
      } else {
        if((~D[j] >> i) & 1) {
          for(int k = 0; k < H; k++) if(decide[k][j] == 1) fail();
          for(int k = 0; k < H; k++) decide[k][j] = 0;
        } else malta.emplace_back(j, 1);
      }
    }
 
    if(min(latte.size(), malta.size()) >= 2) {
      for(int j = 0; j < latte.size(); j++) {
        for(int k = 0; k < malta.size(); k++) {
          decide[latte[j].first][malta[k].first] = (j + k) & 1;
        }
      }
    } else if(latte.size() == 1) {
      for(auto &p : malta) {
        bool ex = false;
        for(int j = 0; j < H; j++) ex |= decide[j][p.first] == p.second;
        decide[latte[0].first][p.first] = ex ? latte[0].second : p.second;
      }
      bool f = false;
      for(int k = 0; k < W; k++) f |= decide[latte[0].first][k] == latte[0].second;
      if(!f) fail();
    } else if(malta.size() == 1) {
      for(auto &p : latte) {
        bool ex = false;
        for(int k = 0; k < W; k++) ex |= decide[p.first][k] == p.second;
        decide[p.first][malta[0].first] = ex ? malta[0].second : p.second;
      }
      bool f = false;
      for(int j = 0; j < H; j++) f |= decide[j][malta[0].first] == malta[0].second;
      if(!f) fail();
    } else {
      for(auto &p : latte) {
        bool f = false;
        for(int k = 0; k < W; k++) f |= decide[p.first][k] == p.second;
        if(!f) fail();
      }
      for(auto &p : malta) {
        bool f = false;
        for(int j = 0; j < H; j++) f |= decide[j][p.first] == p.second;
        if(!f) fail();
      }
    }
    for(int j = 0; j < H; j++) {
      for(int k = 0; k < W; k++) {
        ans[j][k] |= ((uint64_t) (decide[j][k] & 1)) << i;
      }
    }
  }
 
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) cout << ans[i][j] << " ";
    cout << endl;
  }
}
