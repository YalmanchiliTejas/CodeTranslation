#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define IN(a, b, x) (a<=x&&x<b)
#define PB push_back

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const int MOD = 1000000007;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
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

signed main(void)
{
  int l;
  string s, t;
  cin >> l >> s >> t;
  REP(i, l) {
    if(s[i%s.size()] < t[i%t.size()]) break;
    else if(s[i%s.size()] > t[i%t.size()]) {
      swap(s, t);
      break;
    }
  }

  for(int i=0; i*(int)t.size()<=l; ++i) {
    int len = l-(int)t.size()*i;
    if(len%s.size() == 0) {
      REP(j, len/s.size()) {
        cout << s;
      }
      REP(j, i) {
        cout << t;
      }
      cout << endl;
      return 0;
    }
  }
  assert(false);

  return 0;
}
