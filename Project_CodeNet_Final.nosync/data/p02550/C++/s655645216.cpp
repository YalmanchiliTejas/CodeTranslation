//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0xccccccc;
const ll LINF = 0xcccccccccccccccLL;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

#define M 100100

//head

ll n;
int x, m;
bitset<M> check;
ll sum[M];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> x >> m;
  int now = x;
  int cnt = 0;
  while(!check.test(now)) {
    check.set(now);
    cnt++;
    sum[cnt] = sum[cnt-1] + now;
    now = ll(now)*now%m;
  }
  int cnt_ = 0;
  check = 0;
  while(!check.test(now)) {
    check.set(now);
    cnt_++;
    now = ll(now)*now%m;
  }
  if(n <= cnt) {
    cout << sum[n] << endl;
    return 0;
  }
  ll ans = sum[cnt];
  n -= cnt;
  ans += n/cnt_ * (sum[cnt]-sum[cnt-cnt_]);
  n %= cnt_;
  cout << ans + sum[n+cnt-cnt_] - sum[cnt-cnt_] << endl;
}