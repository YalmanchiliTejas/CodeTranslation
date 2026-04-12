#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int main()
{
  int N, H[16], W[16];
  string S[4];
  const string temp = "RGB";
  int bit[16][8][8][3] = {{{{}}}};
  int change[16][8][8][3] = {{{{}}}};
  int v[1 << 16];
  fill_n(v, 1 << 16, INF);
  queue< int > que;

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> H[i] >> W[i];
  }
  for(int i = 0; i < 4; i++) {
    cin >> S[i];
    for(int j = 0; j < 4; j++) {
      S[i][j] = temp.find(S[i][j]);
    }
  }

  for(int k = 0; k < N; k++) {
    for(int i = -3; i < 4; i++) {
      for(int j = -3; j < 4; j++) {
        for(int z = 0; z < 3; z++) {
          auto &tugi = bit[k][i + 3][j + 3][z];
          auto &kaee = change[k][i + 3][j + 3][z];
          for(int l = 0; l < H[k]; l++) {
            if(i + l < 0 || i + l >= 4) continue;
            for(int n = 0; n < W[k]; n++) {
              if(j + n < 0 || j + n >= 4) continue;
              int y = i + l, x = j + n;
              tugi |= (S[y][x] == z) << (y * 4 + x);
              kaee |= 1 << (y * 4 + x);
            }
          }
        }
      }
    }
  }

  que.emplace(0);
  v[0] = 0;
  while(!que.empty()) {
    int p = que.front();
    que.pop();
    if(p == (1 << 16) - 1) {
      cout << v[p] << endl;
      break;
    }
    for(int k = 0; k < N; k++) {
      for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
          for(int z = 0; z < 3; z++) {
            if(bit[k][i][j][z] == 0) continue;
            int s = p & ~change[k][i][j][z] | bit[k][i][j][z];
            if(v[s] > v[p] + 1) {
              v[s] = v[p] + 1;
              que.emplace(s);
            }
          }
        }
      }
    }
  }
}