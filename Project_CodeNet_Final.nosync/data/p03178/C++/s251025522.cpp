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
const ll LINF = 922337203685477580LL;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

const int mod = 1000000007;
//const int mod = 998244353;

struct mint {
  int64_t x;
  mint(int64_t x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(int64_t t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  //for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) {return mint(*this) /= a;}
};

istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

//head

string k;
int d;
int n;
mint dpl[100], dpr[100];
mint *now = dpl, *pre = dpr;
int dp;

inline int num(int i) {return i%d;}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> k >> d;
  n = k.size();
  rep(i, n) {
    memset(now, 0, sizeof(dpl));
    rep(j, k[i]-'0') {
      now[num(dp+j)] += 1;
    }
    rep(j, d) {
      rep(k, 10) {
        now[num(j+k)] += pre[j];
      }
    }
    dp += k[i]-'0';
    dp %= d;
    swap(now, pre);
    //rep(j, d) cout << pre[j] << (j == d-1?'\n':' ');
  }
  if(dp == 0) pre[0] += 1;
  cout << pre[0]-1 << endl;
}