#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define FOR(x,n) for(int x = 0; x < n; x++)
#define FORR(x,n) for(int x = n-1; x >= 0; x--)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define SZ(a) ((int)(a).size())
using namespace std;
typedef long long ll;

const int MXN = 9;
int H, W, total = 0;
bool A[MXN][MXN] = {};

bool can(int x, int y, int cnt) {
  if(x >= H || x < 0 || y >= W || y < 0) return false;
  if(!A[x][y]) return false;
  cnt++;
  if(x == H-1 && y == W-1) return cnt == total;
  return can(x+1, y, cnt) || can(x, y+1, cnt);
}

int main(){
  cin >> H >> W;
  FOR(x,H) FOR(y,W) {
    char c; cin >> c;
    A[x][y] = (c == '#');
    total += A[x][y];
  }
  
  cout << (can(0,0,0) ? "Possible\n" : "Impossible\n");
}