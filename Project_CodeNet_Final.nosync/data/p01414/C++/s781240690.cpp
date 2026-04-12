#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Elm {
  int d, bit;
};

bool operator<(const Elm &e1, const Elm &e2) {
  return e1.d > e2.d;
}

int main() {
  int n; cin >> n;
  vector<int> vh(n), vw(n);
  for(int i=0;i<n;++i) {
    cin >> vh[i] >> vw[i];
  }
  vector<string> s(4);
  for(int i=0;i<4;++i) {
    cin >> s[i];
  }
  int h = 4, w = 4;

  queue<Elm> que;
  vector<int> d(1<<16, INF);
  que.push({0, (1<<16)-1});
  d[(1<<16)-1] = 0;
  bool ok = false;
  while(!que.empty()) {
    if(ok) break;
    auto now = que.front(); que.pop();
    if(d[now.bit] < now.d) continue;
    //cout << now.d << ":" << bitset<16>(now.bit) << endl;
    vector<bitset<4>> bs(4);
    for(int i=0;i<4;++i) {
      for(int j=0;j<4;++j) {
        bs[i][j] = (now.bit>>(i*4+j))&1;
      }
    }

    for(int i=0;i<n;++i) {
      if(ok) break;
      int h1 = -vh[i]+1, w1 = -vw[i]+1;
      for(int j=h1;j<h;++j) {
        if(ok) break;
        for(int k=w1;k<w;++k) {
          if(ok) break;
          bool some = false, r = true, g = true, b = true;
          vector<bitset<4>> nxt = bs;
          for(int l=max(0, j);l<min(j+vh[i], h);++l) {
            for(int m=max(0, k);m<min(k+vw[i], w);++m) {
              if(!nxt[l][m]) continue;
              nxt[l][m] = 0;
              some = true;
              r &= s[l][m] == 'R';
              g &= s[l][m] == 'G';
              b &= s[l][m] == 'B';
            }
          }
          if(!some) continue;
          if(r || g || b) {
            int nxtbit = 0;
            for(int l=0;l<4;++l) {
              for(int m=0;m<4;++m) {
                nxtbit ^= nxt[l][m]<<(l*4+m);
              }
            }
            if(d[nxtbit] > now.d+1) {
              d[nxtbit] = now.d+1;
              que.push({d[nxtbit], nxtbit});
              if(nxtbit == 0) ok = true;
            }
          }
        }
      }
    }
  }

  cout << d[0] << endl;
}
