//#include <atcoder/modint>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
typedef long long ll;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPR(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, m, n) for(int i=m; i<n; i++)
#define ALL(v) v.begin(), v.end()
#define SIZE(x) ll(x.size()) 
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 2e9;
const ll LINF = (1LL<<60);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,x,m;
  cin >> n >> x >> m;
  vector<ll> tmp(m);
  REP(i,m) tmp[i] = i*i % m;

  ll sum = 0;
  vector<bool> seen(m, false);
  vector<ll> path;
  REP(i,n){
    if(seen[x]){
      int ind = 0;
      while(path[ind]!=x) ind++;
      int cyc = SIZE(path) - ind;
      ll cyc_sum = 0;
      FOR(j,ind,SIZE(path)) cyc_sum += path[j];
      sum += cyc_sum * ll((n-i)/cyc);
      REP(j,(n-i)%cyc) sum += path[j+ind];
      break;
    }

    sum += x;
    seen[x] = true;
    path.push_back(x);
    x = x*x % m;
  }

  cout << sum << endl;
  return 0;
}
