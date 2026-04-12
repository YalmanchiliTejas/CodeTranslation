#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int ll
using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define PB push_back

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const int MOD = 1000000007;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template <typename T> bool IN(T a, T b, T x) { return a<=x&&x<b; }
template<typename T> T ceil(T a, T b) { return a/b + !!(a%b); }
template<class S,class T>
ostream &operator <<(ostream& out,const pair<S,T>& a){
  out<<'('<<a.first<<','<<a.second<<')';
  return out;
}
template<class T>
ostream &operator <<(ostream& out,const vector<T>& a){
  out<<'[';
  REP(i, a.size()) {out<<a[i];if(i!=a.size()-1)out<<',';}
  out<<']';
  return out;
}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

char col[] = {'R', 'G', 'B'};
string board[4];
int n, d[1<<16], h[20], w[20];
signed main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  REP(i, n) cin >> h[i] >> w[i];
  REP(i, 4) cin >> board[i];

  REP(i, 1<<16) d[i] = INF;
  d[0] = 0;
  queue<int> que;
  que.push(0);

  while(que.size()) {
    int bit = que.front(); que.pop();
    // cout << bit << endl;
    if(bit == (1LL<<16)-1) break;
    REP(i, n) FOR(y, -h[i]+1, 4) FOR(x, -w[i]+1, 4) REP(c, 3) {
      int n_bit = bit;
      FOR(ny, max(0LL, y), min(y+h[i],4LL)) FOR(nx, max(0LL, x), min(x+w[i],4LL)) {
        if(board[ny][nx] == col[c]) n_bit |= 1<<(ny*4+nx);
        else n_bit &= ~(1<<(ny*4+nx));
      }
      // cout << bitset<16>(n_bit) << endl;
      if(d[n_bit] == INF) {
        d[n_bit] = d[bit] + 1;
        que.push(n_bit);
      }
    }
  }

  if(d[(1LL<<16)-1] == INF) cout << -1 << endl;
  else cout << d[(1LL<<16)-1] << endl;

  return 0;
}

