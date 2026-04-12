//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()


int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> path(n, vector<bool>(n, false));//iとjが繋がってるならpath[i][j]=path[j][i]=true;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    path[a][b] = path[b][a] =true;
  }
  vector<int> a(n);
  rep(i, n) a[i] = i;
  
  int ans = 0;
  do {
    if (a[0] != 0) continue;
    bool flag = true;
    rep(i, n-1) {
      if (!path[a[i]][a[i+1]])  {
        flag = false;
        break;
      }
    }
    
    if (flag) ans++;
    
  } while (next_permutation(all(a)));
  
  cout << ans << endl;
  return 0;
}