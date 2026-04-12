#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;
const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
template <typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if(a < b) {a = b; return true;}
  return false;
}
template <typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if(a > b) {a = b; return true;}
  return false;
}
template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}
template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for(int i=0;i<((int)(v.size()));++i) {
    if(i) os << " ";
    os << v[i];
  }
  return os;
}
vvll dp1;
vvll dp2;
vll dp3;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  ll n, m, w, t; cin >> n >> m >> w >> t;
  map<string, pair<ll, ll>> mp1;
  for(int i=0;i<(m);++i) {
    string s; ll v, p;
    cin >> s >> v >> p;
    mp1[s] = make_pair(v, p);
  }
  vector<map<string, ll>> v(n+1);
  vector<ll> x(n+1), y(n+1);
  for(int i=0;i<(n);++i) {
    ll l, x1, y1; cin >> l >> x1 >> y1;
    x[i+1] = x1;
    y[i+1] = y1;
    for(int j=0;j<(l);++j) {
      string r; ll q;
      cin >> r >> q;
      v[i+1][r] = q;
    }
  }
  dp1.resize(1<<(n+1), vll(n+1, LINF));
  dp1[1][0] = 0;
  for(int i=0;i<(n+1);++i) {
    for(int j=0;j<(1<<(n+1));++j) {
      if(__builtin_popcount(j) != i) continue;
      for(int k=0;k<(n+1);++k) {
        if(((j>>k)&1) == 0) {
          for(int l=0;l<(n+1);++l) {
            if(dp1[j][l] == LINF) continue;
            chmin(dp1[j | (1 << k)][k], dp1[j][l] + abs(x[l] - x[k]) + abs(y[l] - y[k]));
          }
        }
      }
    }
  }
  vll d(1<<(n+1), LINF);
  for(int i=0;i<(n+1);++i) {
    for(int j=0;j<(1<<(n+1));++j) {
      chmin(d[j], dp1[j][i] + abs(x[i]) + abs(y[i]));
    }
  }
  vll val(1<<(n+1), -LINF);
  for(int i=0;i<(1<<(n+1));++i) {
    dp2.clear();
    dp2.resize(n+2, vll(w+1, -LINF));
    dp2[0][0] = 0;
    for(int j=0;j<(n+1);++j) {
      if((i>>j)&1) {
        for(int k=0;k<(w+1);++k) {
          chmax(dp2[j+1][k], dp2[j][k]);
        }
        for(auto &e: v[j]) {
          ll value = mp1[e.first].second - e.second;
          ll weight = mp1[e.first].first;
          for(int k=0;k<(w+1);++k) {
            if(dp2[j][k] == -LINF) continue;
            if(k + weight <= w) {
              chmax(dp2[j][k+weight], dp2[j][k] + value);
              chmax(dp2[j+1][k+weight], dp2[j][k] + value);
            }
          }
        }
      } else {
        for(int k=0;k<(w+1);++k) {
          dp2[j+1][k] = dp2[j][k];
        }
      }
    }
    for(int k=0;k<(w+1);++k) {
      chmax(val[i], dp2[n+1][k]);
    }
  }
  dp3.resize(t+1, -LINF);
  dp3[0] = 0;
  for(int i=0;i<(t);++i) {
    for(int j=0;j<(1<<(n+1));++j) {
      if(d[j] == -LINF || val[j] == -LINF) continue;
      if(dp3[i] == -LINF) continue;
      if(i + d[j] <= t) {
        chmax(dp3[i+d[j]], dp3[i] + val[j]);
      }
    }
  }
  ll ans = 0;
  for(int i=0;i<(t+1);++i) {
    chmax(ans, dp3[i]);
  }
  cout << ans << endl;
}

