#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cassert>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
#include <iomanip>
#include <fstream>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<b?(a=b,1):0)
#define chmin(a,b) (a>b?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> pii;

struct BUT {
  int n;                        // n-ary
  char label;
  int c1,c2;                    // component
  BUT() {}
  BUT(char label) : n(0),label(label) {}
  BUT(char label, int c) : n(1), label(label), c1(c) {}
  BUT(char label, int c1, int c2) : n(2), label(label), c1(c1), c2(c2) {}
} buts[1000];

int butnum;

int parse(const string &s) {    // テ」ツδ妥」ツδシテ」ツつケテ」ツ?療」ツ?ヲIDテ」ツつ津ィツソツ氾」ツ??
  if (s.size() == 1) {          // 0-ary
    buts[butnum] = BUT(s[0]);
  } else {
    int comma = -1;
    int cnt = 0;
    REP(i,s.size()) {
      if (s[i] == '(') cnt++;
      else if (s[i] == ')') cnt--;
      if (cnt == 1 && s[i] == ',') comma = i;
    }
    if (comma == -1) {          // unary
      int c = parse(s.substr(2,s.size()-3));
      buts[butnum] = BUT(s[0],c);
    } else {                    // binary
      int c1 = parse(s.substr(2,comma-2));
      int c2 = parse(s.substr(comma+1, s.size()-comma-2));
      buts[butnum] = BUT(s[0],c1,c2);
    }
  }
  return butnum++;
}

typedef pair<vector<string>, int> P;
P diagram(int id) {
  BUT b = buts[id];
  if (b.n == 0) {
    return P(vector<string>(1,string(1,b.label)), 0);
  } else if (b.n == 1) {
    P p = diagram(b.c1);
    vector<string> d = p.first;
    int pos = p.second;
    d.push_back(string(d[0].size(), ' '));
    d.push_back(string(d[0].size(), ' '));
    d[d.size()-2][pos] = '-';
    d[d.size()-1][pos] = b.label;
    return P(d,pos);
  } else {
    P p1 = diagram(b.c1);
    P p2 = diagram(b.c2);
    vector<string> d1 = p1.first, d2 = p2.first;
    int pos1 = p1.second, pos2 = p2.second;
    int h1 = d1.size(), h2 = d2.size();
    int w1 = d1[0].size(), w2 = d2[0].size();
    int h = max(h1,h2);
    int maxdis = w1-pos1 + pos2;

    for (int x12=-w2+1; x12<=w1+1; ++x12) {
      int x1,x2;
      if (x12<0) {
        x1 = -x12;
        x2 = 0;
      } else {
        x1 = 0;
        x2 = x12;
      }
      int w = max(x1+w1,x2+w2);
      int y1 = h-h1, y2 = h-h2;

      // テ・ツキツヲテ」ツ?ョrootテ」ツ?古・ツ渉ウテ」ツ?ョrootテ」ツつ暗」ツつ甘・ツ渉ウテ」ツ?ォテ」ツ??」ツ?淌」ツつ嘉」ツ??」ツつ?
      if (x1+pos1 >= x2+pos2) continue;
      bool ok = 1;
      vector<string> nxt(h+2,string(w,' '));
      bool f[h][w];
      memset(f,0,sizeof(f));
      REP(i,h1) REP(j,w1)
        nxt[i+y1][j+x1] = d1[i][j];
      REP(i,h2) REP(j,w2) {
        if (d2[i][j] != ' ') {
          if (nxt[i+y2][j+x2] != ' ') ok = 0;
          nxt[i+y2][j+x2] =  d2[i][j];
          f[i+y2][j+x2] = 1;
        }
      }
      // cout << h << " " << w << endl;
      // REP(i,h) {
      //   REP(j,w) cout << nxt[i][j];
      //   cout << endl;
      // }
      if (ok) {
        static const int dy[4] = {-1,0,1,0};
        static const int dx[4] = {0,1,0,-1};
        REP(i,h)REP(j,w) {
          if (nxt[i][j] != ' ') {
            REP(k,4) {
              int y=i+dy[k];
              int x=j+dx[k];
              if (valid(y,x,h,w)) {
                if (nxt[y][x] != ' ' && f[i][j] ^ f[y][x]) ok = 0;
              }
            }
          }
        }
        if (ok) {
          int xp1 = x1 + pos1;
          int xp2 = x2 + pos2;
          int npos = xp1 + (xp2-xp1)/2;
          for (int x=xp1; x<=xp2; ++x) nxt[h][x] = '-';
          nxt[h+1][npos] = b.label;
          return P(nxt,npos);
        }
      }
    }
  }
  assert(0);
}

int main() {
  char c;
  int cs = 0;
  do {
    string s;
    while(cin >> c, c!=';'&&c!='.') {
      s += string(1,c);
    }
    // cout << s << endl;
    butnum = 0;
    int root = parse(s);
    vector<string> ans = diagram(root).first;
    printf("%d:\n", ++cs);
    REP(i,ans.size()) {
      int len = ans[i].size();
      for(int j=len-1; j>=0; --j) {
        if (ans[i][j]!=' ') break;
        len=j;
      }
      REP(j,len) cout << ans[i][j];
      cout << endl;
    }
  } while(c != '.');
}