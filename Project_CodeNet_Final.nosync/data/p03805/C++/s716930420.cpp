#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 55);
 
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(n, 0));
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a][b] = 1;
    g[b][a] = 1;
  }
  vector<int> v(n);
  rep(i,n) v[i] = i;
  int res = 0;
  do {
    int ok = 1;
    for (int i = 0; i < n-1; i++) {
      ok &= (g[v[i]][v[i+1]]);
    }
    res += ok;
  } while (next_permutation(v.begin() + 1, v.end()));
  cout << res << endl;
  return 0;
}