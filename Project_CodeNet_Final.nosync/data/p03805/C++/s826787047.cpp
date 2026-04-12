#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
int gg[maxn][maxn];
int main(){
  int n, m; cin >> n >> m;
  for(int i = 0; i < m; i++){
    int x, y; cin >> x >> y;
    gg[x][y] = gg[y][x] = 1;
  }
  vector<int> o(n - 1);
  iota(o.begin(), o.end(), 2);
  int ans = 0;
  do{
  	int last = 1, good = 1;
    for(int v : o){
      good &= gg[last][v];
      last = v;
    }
    ans += good;
  } while(next_permutation(o.begin(), o.end()));
  cout << ans << endl;
  return 0;
}