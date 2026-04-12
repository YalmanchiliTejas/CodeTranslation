#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;
const int INF = 1001001001;

bool G[10][10];

int main() {
  int n,m; cin >> n >> m;
  rep(i,m){
    int a, b; cin >> a >> b; --a,--b;
    G[a][b] = G[b][a] = true;
  }

  vector<int> ord(n);
  rep(i,n) ord[i] = i;
  int res = 0;
  do{
    if(ord[0] != 0) break;

    bool ok = true;
    rep(i,n-1){
      int from = ord[i];
      int to = ord[i+1];
      if(!G[from][to]) ok = false;
    }
    if(ok) ++res;
  }while(next_permutation(ord.begin(), ord.end()));

  cout << res << endl;
  return 0;
}