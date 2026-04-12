#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int> > v(n+1, vector<int>(n+1, 0));
  int a, b;
  rep(i, m){
    cin >> a >> b;
    v[a][b] = 1;
  }
  vector<int> p(n);
  rep(i, n) p[i] = i + 1;
  int ans = 0;
  do {
    bool f = true;
    rep(i, n-1){
      if (v[p[i]][p[i+1]] == 0 &&
          v[p[i+1]][p[i]] == 0){
        f = false;
        break;
      }
    }
    if (f == true) ans++;
  } while (next_permutation(p.begin()+1, p.end()));
  cout << ans << endl;
  return 0;
}