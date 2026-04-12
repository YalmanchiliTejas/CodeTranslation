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
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

typedef pair<int,int> pii;

int r,c,m;
char ba[50][50];
map<pii, int> mp;

vector<int> dfsres;
bool visited[50][50];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
bool dfs(int y1, int x1, int y2, int x2) {
  visited[y1][x1] = 1;
  if (y1==y2 && x1==x2) return 1;
  REP(k,4) {
    int yy = y1+dy[k];
    int xx = x1+dx[k];

    if (yy<0||yy>=r||xx<0||xx>=c) continue;
    if (ba[yy][xx] == '.' && !visited[yy][xx]) {
      dfsres.push_back(mp[pii(yy,xx)]);
      if (dfs(yy,xx,y2,x2))
        return 1;
      dfsres.pop_back();
    }
  }
  return 0;
}

int main() {
  cin >> r >> c >> m;

  int ct = 0;
  REP(i,r) {
    REP(j,c) {
      cin >> ba[i][j];
      if (ba[i][j] == '.') {
        mp[pii(i,j)] = ct++;
      }
    }
  }
  int a[ct], b[ct], c1[ct];
  REP(i,r) {
    REP(j,c) {
      int x;
      cin >> x;
      if (mp.count(pii(i,j))) {
        a[mp[pii(i,j)]] = x;
      }
    }
  }
  REP(i,r) {
    REP(j,c) {
      int x;
      cin >> x;
      if (mp.count(pii(i,j))) {
        b[mp[pii(i,j)]] = x;
      }
    }
  }
  REP(i,r) {
    REP(j,c) {
      int x;
      cin >> x;
      if (mp.count(pii(i,j))) {
        c1[mp[pii(i,j)]] = x;
      }
    }
  }
  vector<int> root;
  int maey, maex;
  REP(i,m) {
    int y,x;
    cin >> y >> x;
    if (i == 0) {
      root.push_back(mp[pii(y,x)]);
    } else {
      if (maey==y&&maex==x) {
        root.push_back(mp[pii(y,x)]);
      }
      memset(visited,0,sizeof(visited));
      dfsres.clear();
      dfs(maey, maex, y, x);
      FOR(it, dfsres) {
//        cout << *it << " ";
        root.push_back(*it);
      }
//      cout << endl;
    }
    maey = y; maex = x;
  }
  
  
  // cout << "root" << endl;
  // FOR(it, root)
  //   cout << *it << " ";
  // cout << endl;
  vector<int> v[ct];


  int mae[ct];
  memset(mae,-1,sizeof(mae));
  REP(i, root.size()) {
    int id = root[i];
    if (mae[id] != -1) {
      v[id].push_back(i-mae[id]);
    }
    mae[id] = i;
  }

    
  long long res = 0;
  REP(i,ct) {
    bool on = 0;
//    cout << "i = " << i << endl;
    REP(j, v[i].size()) {
      int mean = v[i][j];
//      cout << v[i][j] << " ";
      if (!on) {
        res += b[i]; 
      }
      if (a[i]*mean < b[i]+c1[i]) {
        on = 1;
        res += a[i]*mean;
      } else {
        res += c1[i];
        on = 0;
      }
    }
//    cout << endl;
    if (mae[i] != -1) {
      if (!on) {
        res += b[i] + c1[i];
      } else
        res += c1[i];
    }
    //cout << "res = " << res << endl;
  }
  cout << res << endl;
}