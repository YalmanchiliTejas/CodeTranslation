#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define INF 1e9
#define all(v) v.begin(), v.end()
typedef long long ll;

bool G[10][10];

int main(){
  int n, m; cin >> n >> m;
  rep(i, m){
    int a, b; cin >> a >> b;
    a--, b--;
    G[a][b] = true;
    G[b][a] = true;
  }

  vector<int> ord(n);
  rep(i, n) ord[i] = i;

  int res = 0;
  do{
    if(ord[0] != 0) break;
    bool ok = true;
    rep(i, n-1){
      if(!G[ord[i]][ord[i+1]]){
        ok = false;
        break;
      }
    }
    if(ok) res++;
  }while(next_permutation(all(ord)));

  cout << res << endl;

  return 0;
}
