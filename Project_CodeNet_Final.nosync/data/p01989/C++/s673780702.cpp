#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int ll
using PII = pair<int, int>;
template <typename T> using V = vector<T>;
template <typename T> using VV = vector<V<T>>;
template <typename T> using VVV = vector<VV<T>>;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define PB push_back

const ll INF = (1LL<<60);
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

signed main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int ret = 0;
  REP(i, s.size()) FOR(j, i+1, s.size()) FOR(k, j+1, s.size()) {
    auto check = [&](string t) {
      // cout << t << " ";
      bool flag = true;
      if(t.size() == 0) return false;
      if(t.size() >= 2 && t[0]=='0') return false;
      int num = stol(t);
      if(num < 0 || num > 255) flag = false;
      return flag;
    };
    if(check(s.substr(0, i+1)) && check(s.substr(i+1, j-i)) 
      && check(s.substr(j+1, k-j)) && check(s.substr(k+1, s.size()-k-1))) 
    {
        ret++;
    }
    // cout << endl;
  }
  cout << ret << endl;

  return 0;
}

