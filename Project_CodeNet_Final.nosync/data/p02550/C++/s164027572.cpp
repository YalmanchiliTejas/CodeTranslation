#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl;

template<class T>
ostream &operator<<(ostream &os, const vector <T> &v) {
  os << "[";
  REP(i, SZ(v)) {
    if (i) os << ", ";
    os << v[i];
  }
  return os << "]";
}

template<class T, class U>
ostream &operator<<(ostream &os, const pair <T, U> &p) {
  return os << "(" << p.first << " " << p.second << ")";
}

template<class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
const ld eps = 1e-9;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  ll n, x, m; cin >> n >> x >> m;
  ll orx = x;

  ll ans = 0;
  ll cnt = 0;
  vector<int> v(m, -1);
  if(x < m) v[x] = 0;
  REP(i, n) {
    ans += x;
    x %= m;
    x = x * x % m;
    if(x == 0) {
      cout << ans << endl;
      return 0;
    }
    //cout << x << endl;
    if(v[x] != -1) break;
    cnt++;
    v[x] = cnt;
  }
  if(cnt == n) {
    cout << ans << endl;
    return 0;
  }
  //cout << cnt << endl;
  //cout << x << endl;

  ll be = v[x], ed = cnt+1;
  //cout << be << " " << ed << endl;
  ll su = 0;
  ll tmpx = x;
  while(1) {
    su += x;
    x = x * x % m;
    if(x == tmpx) break;
  }
  ans -= su;

  //cout << ans << ":" << su << endl;

  ll add = 0;
  x = tmpx;
  REP(i, (n-be) % (ed - be)) {
    add += x;
    x = x * x % m;
  }
  cout << ans + su * ((n - be) / (ed - be)) + add << endl;

  return 0;
}
