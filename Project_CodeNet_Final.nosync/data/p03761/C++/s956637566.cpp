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
  int n;
  cin >> n;
  vector<string> s(n);
  REP(i, n) cin >> s[i];
  vector<vector<int>> a(n, vector<int>(26, 0));
  REP(i, n){
    REP(j, s[i].size()) a[i][s[i][j] - 'a']++;
  }
  string ans;
  REP(i, 26){ 
    int num = INF;
    REP(j, n) chmin(num, a[j][i]);
    if(num > 0) ans += string(num, 'a'+i);
  }
  cout << ans << endl;
  return 0;
}