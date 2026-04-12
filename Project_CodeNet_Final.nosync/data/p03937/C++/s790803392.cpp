#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define pb push_back
#define in ,
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define dep(i, a, n) for(int i = (a); i >= (n); i--)
#define mod 1e9+7

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

char m[8][8];
int h, w;

int solve(int x, int y) {
  int f1 = false, f2 = false;
  if(!x && !y) f1 = true;
  if(x > 0) if(m[x - 1][y] == '#') f1 = !f1;
  if(y > 0) if(m[x][y - 1] == '#') f1 = !f1;
  if(!f1) return 0;
  if(x == h - 1 && y == w - 1) return 1;
  if(x < h) if(m[x + 1][y] == '#') f2 = !f2;
  if(y < w) if(m[x][y + 1] == '#') f2 = !f2;
  if(!f2) return 0;
  if(x < h) {
    if(m[x + 1][y] == '#') solve(x + 1, y);
    else solve(x, y + 1);
  }else solve(x, y + 1);

}

int main() {
  cin >> h >> w;
  rep(i, 0, h) rep(j, 0, w) cin >> m[i][j];

  cout << (solve(0, 0) ? "Possible" : "Impossible") << endl;
}
