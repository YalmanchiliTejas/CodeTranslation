#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

int main(void){
  int n, m;
  cin >> n >> m;
  vector<set<int>> to(n);
  REP(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    to[a].insert(b);
    to[b].insert(a);
  }
  vector<int> p(n);
  REP(i, n) p[i] = i;
  int ans = 0;
  do{
    if(p[0] != 0) break;
    bool ok = true;
    REP(i, n-1){
      if(to[p[i]].count(p[i+1]) == 0) ok = false;
    }
    if(ok) ans++;
  }while(next_permutation(ALL(p)));
  cout << ans << endl;
  return 0;
}