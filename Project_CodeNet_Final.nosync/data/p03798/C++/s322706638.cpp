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
  ll n;
  string s;
  cin >> n >> s;
  bool a[] = {true, false};
  bool b[] = {true, false};
  vector<bool> v(n+1);
  REP(i, 2) REP(j, 2){
    v[0] = a[i];
    v[1] = b[j];
    FOR(k, 1, n){
      if(v[k]){
        if(s[k] == 'o'){
          v[k+1] = v[k-1];
        }else{
          v[k+1] = !v[k-1];
        }
      }else{
        if(s[k] == 'x'){
          v[k+1] = v[k-1];
        }else{
          v[k+1] = !v[k-1];
        }
      }
    }
    if(v[0] != v[n]) continue;
    if(v[0]){
      if(s[0] == 'o' && v[n-1] != v[1]) continue;
      if(s[0] == 'x' && v[n-1] == v[1]) continue;
    }else{
      if(s[0] == 'x' && v[n-1] != v[1]) continue;
      if(s[0] == 'o' && v[n-1] == v[1]) continue;
    }
    REP(k, n){
      if(v[k]) printf("S");
      else printf("W");
    }
    printf("\n");
    return 0;
  }
  cout << -1 << endl;
  return 0;
}