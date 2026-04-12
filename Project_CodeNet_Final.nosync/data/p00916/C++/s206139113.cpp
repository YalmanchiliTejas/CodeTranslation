#include <bits/stdc++.h>

using namespace std;

#define LOG(...) fprintf(stderr, __VA_ARGS__)
//#define LOG(...)
#define FOR(i, a, b) for(int i=(int)(a); i<(int)(b); ++i)
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define SQ(n) (n) * (n)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Rect {
  int l, t, r, b;
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int y, int x, int h, int w, vvi &field){
  field[y][x] = 2;
  REP(i, 4){
    int sx = x + dx[i];
    int sy = y + dy[i];
    if(sx < 0 || w <= sx || sy < 0 || h <= sy) continue;
    if(field[sy][sx] == 0) {
      dfs(sy, sx, h, w, field);
    }
  }
}

int main() {
  int n;
  while(cin >> n, n) {
    vector<Rect> rect(n);
    vi hol, ver;
    map<int, int> hol_map, ver_map;
    REP(i, n){
      cin >> rect[i].l >> rect[i].t >> rect[i].r >> rect[i].b;
      hol.push_back(rect[i].l);
      hol.push_back(rect[i].r);
      ver.push_back(rect[i].t);
      ver.push_back(rect[i].b);
    }
    SORT(hol);
    SORT(ver);

    vvi field((ver.size()) * 2 + 1, vi((hol.size()) * 2 + 1, 0));

    REP(i, n){
      int l = (find(ALL(hol), rect[i].l) - hol.begin()) * 2 + 1;
      int r = (find(ALL(hol), rect[i].r) - hol.begin()) * 2 + 1;
      int t = (find(ALL(ver), rect[i].t) - ver.begin()) * 2 + 1;
      int b = (find(ALL(ver), rect[i].b) - ver.begin()) * 2 + 1;
      // LOG("%d %d %d %d\n", l, r, t, b);
      FOR(x, l, r + 1){
        field[t][x] = true;
        field[b][x] = true;
      }
      FOR(y, b, t + 1){
        field[y][l] = true;
        field[y][r] = true;
      }
    }

    int h = field.size(), w = field[0].size();
    int cnt = 0;
    REP(y, h){
      REP(x, w){
        if(field[y][x] == 0) {
          cnt++;
          dfs(y, x, h, w, field);
        }
      }
    }
    cout << cnt << endl;

    // REP(y, h){
    //   REP(x, w){
    //     LOG("%d", field[y][x] & 1);
    //   }
    //   LOG("\n");
    // }

  }
}