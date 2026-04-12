#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <bitset>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

struct rect {
  int x1,y1;
  int x2,y2;
};
const bool operator<(const rect &a, const rect &b) {
  return a.x1!=b.x1?a.x1<b.x1:a.y1!=b.y1?a.y1<b.y1 :
    a.x2!=b.x2?a.x2<b.x2:a.y2<b.y2;
}

bool visited[1<<16];

int main() {
  int n;
  cin >> n;
  set<rect> se;

  REP(i,n) {
    int h, w;
    cin >> h >> w;
    for (int r=-3; r<=3; ++r) {
      for (int c=-3; c<=3; ++c) {
        int x1=4,y1=4,x2=0,y2=0;
        for (int rr=max(0,r); rr<min(4,r+h); ++rr) {
          for (int cc=max(0,c); cc<min(4,c+w); ++cc) {
            x1 = min(x1, cc);
            y1 = min(y1, rr);
            x2 = max(x2, cc);
            y2 = max(y2, rr);
          }
        }
        if (x1!=4) {
          se.insert((rect){x1,y1,x2,y2});
        }
      }
    }
  }
  int ba[4][4];
  REP(i,4) {
    REP(j,4) {
      char c;
      cin >> c;
      if (c=='R') ba[i][j] = 0;
      else if (c=='G') ba[i][j] = 1;
      else ba[i][j] = 2;
    }
  }

  vector<int> correct;
  vector<int> wrong;

  FOR(it, se) {
//    printf("(%d,%d) (%d,%d)\n", it->x1,it->y1,it->x2,it->y2);
    int x1=it->x1,y1=it->y1,x2=it->x2,y2=it->y2;
    REP(c, 3) {
      int cor=0, wro=0;
      for (int x=x1;x<=x2;++x) {
        for (int y=y1;y<=y2;++y) {
          if (ba[y][x] == c) cor |= 1<<(y*4+x);
          else wro |= 1<<(y*4+x);
        }
      }
      // if (x1==2&&y1==1&&x2==2&&y2==1) {
      //   cout << cor << " " << wro << endl;
      // }
      correct.push_back(cor);
      wrong.push_back(wro);
    }
  }
  int m = correct.size();
  typedef pair<int,int> pii;
  queue<pii> Q;
  Q.push(pii(0,0));
  while(!Q.empty()) {
    pii p = Q.front(); Q.pop();
    int S = p.first, num = p.second;
    if (visited[S]) continue;
    // if (num == 1) {
    //   stringstream ss;
    //   ss << bitset<16>(S);
    //   string s = ss.str();
    //   if (s[6]=='1') {
    //     REP(i,4) {
    //       REP(j,4) {
    //         cout << s[i*4+j];
    //       }
    //       cout << endl;
    //     }
    //     cout << endl;
    //   }
    // }
      //cout << S << endl;
    visited[S] = 1;
    if (S==(1<<16)-1) {
      cout << num << endl;
      break;
    }
    REP(i, m) {
      int s = S;
      s |= correct[i];
      s &= ~wrong[i];
      if (!visited[s]) {
        Q.push(pii(s, num+1));
      }
    }
  }
}