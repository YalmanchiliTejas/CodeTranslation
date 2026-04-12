#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,n) for(int i = 1; i < n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
using vs = vector<string>;
using vb = vector<bool>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, w;
  cin >> h >> w;
  vs f(h);
  rep(i,h) cin >> f[i];
  rep(i,h) {
    bool ok = true;
    rep(j,w) {
      if(f[i][j] == '#') ok = false;
    }
    if(ok) {
      rep(j,w) f[i][j] = '-';
    }
  }
  rep(i,w) {
    bool ok = true;
    rep(j,h) {
      if(f[j][i] == '#') ok = false;
    }
    if(ok) {
      rep(j,h) f[j][i] = '-';
    }
  }
  rep(i,h) {
    bool ok = false;
    rep(j,w) {
      if(f[i][j] != '-') {
        cout << f[i][j];
        ok = true;
      }
    }
    if(ok) cout << endl;
  }
}