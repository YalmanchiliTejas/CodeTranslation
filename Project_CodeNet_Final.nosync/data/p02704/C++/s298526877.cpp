#pragma region template
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vull = vector<ull>;
using vvull = vector<vull>;
using vvvull = vector<vvull>;
using vld = vector<ld>;
using vvld = vector<vld>;
using vvvld = vector<vvld>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
template <typename T>
using pqrev = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, n) for (ll i = 0, i##_end = (n); i < i##_end; i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for (ll i = (a), i##_end = (b); i < i##_end; i++)
#define reprb(i, a, b) for (ll i = (b)-1, i##_end = (a); i >= i##_end; i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
//*
constexpr ll MOD = 1e9 + 7;
/*/
constexpr ll MOD = 998244353;
//*/
constexpr ll INF = 1e+18;
constexpr ld EPS = 1e-12L;
constexpr ld PI = 3.14159265358979323846L;
constexpr ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
constexpr ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
template <typename S, typename T>
constexpr bool chmax(S &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename S, typename T>
constexpr bool chmin(S &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif
template <typename T>
bool print_(const T &a) {
  cout << a;
  return true;
}
template <typename T>
bool print_(const vector<T> &vec) {
  for (auto &a : vec) {
    cout << a;
    if (&a != &vec.back()) {
      cout << " ";
    }
  }
  return false;
}
template <typename T>
bool print_(const vector<vector<T>> &vv) {
  for (auto &v : vv) {
    for (auto &a : v) {
      cout << a;
      if (&a != &v.back()) {
        cout << " ";
      }
    }
    if (&v != &vv.back()) {
      cout << "\n";
    }
  }
  return false;
}
void print() { cout << "\n"; }
template <typename Head, typename... Tail>
void print(Head &&head, Tail &&... tail) {
  bool f = print_(head);
  if (sizeof...(tail) != 0) {
    cout << (f ? " " : "\n");
  }
  print(forward<Tail>(tail)...);
}
#pragma endregion

void Pr(){
  cout << -1 << endl;
  exit(0);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  vull s(n);
  rep(i, n){
    cin >> s[i];
  }
  vull t(n);
  rep(i, n){
    cin >> t[i];
  }
  vull u(n);
  rep(i, n){
    cin >> u[i];
  }
  vull v(n);
  rep(i, n){
    cin >> v[i];
  }
  vvull ans(n, vull(n, 0));
  vvvull ans2(64, vvull(n, vull(n, 2)));
  rep(bit, 64){
    rep(i, n){
      rep(j, n){
        if(!s[i] && ((u[i] >> bit)&1)){
          ans2[bit][i][j] = 1;
        }
        if(s[i] && !((u[i] >> bit)&1)){
          ans2[bit][i][j] = 0;
        }
        if(!t[j] && ((v[j] >> bit)&1)){
          if(ans2[bit][i][j] == 0){
            Pr();
          }
          ans2[bit][i][j] = 1;
        }
        if(t[j] && !((v[j] >> bit)&1)){
          if(ans2[bit][i][j] == 1){
            Pr();
          }
          ans2[bit][i][j] = 0;
        }
      }
    }
    int umeflg = 0;
    rep(i, n){
      bool f = 1;
      rep(j, n){
        if(ans2[bit][i][j] != 2){
          f = 0;
        }
      }
      if(f){
        umeflg = 2;
        break;
      }
    }
    rep(j, n){
      bool f = 1;
      rep(i, n){
        if(ans2[bit][i][j] != 2){
          f = 0;
        }
      }
      if(f){
        umeflg++;
        break;
      }
    }
    if(umeflg == 3){
      if(n == 1){
        ans2[bit][0][0] = 0;
      }else{
        rep(i, n){
          rep(j, n){
            ans2[bit][i][j] = (i+j)%2;
          }
        }
      }
    }else if(umeflg == 2){
      int appear = 0;
      rep(i, n){
        rep(j, n){
          if(ans2[bit][i][j] == 0){
            appear |= 1;
          }
          if(ans2[bit][i][j] == 1){
            appear |= 2;
          }
        }
      }
      if(appear == 3){
        rep(i, n){
          if(!s[i] && !((u[i] >> bit)&1)){
            rep(j, n){
              ans2[bit][i][j] = 0;
            }
          }
          if(s[i] && ((u[i] >> bit)&1)){
            rep(j, n){
              ans2[bit][i][j] = 1;
            }
          }
        }
      }else{
        bool f = 0;
        rep(i, n){
          if(appear == 1 && s[i] && ((u[i] >> bit)&1)){
            f = 1;
            rep(j, n){
              ans2[bit][i][j] = 1;
            }
          }
          if(appear == 2 && !s[i] && !((u[i] >> bit)&1)){
            f = 1;
            rep(j, n){
              ans2[bit][i][j] = 0;
            }
          }
        }
        if(f){
          rep(i, n){
            if(!s[i] && !((u[i] >> bit)&1)){
              rep(j, n){
                ans2[bit][i][j] = 0;
              }
            }
            if(s[i] && ((u[i] >> bit)&1)){
              rep(j, n){
                ans2[bit][i][j] = 1;
              }
            }
          }
        }else{
          vll lst;
          rep(i, n){
            if(appear == 1 && !s[i] && !((u[i] >> bit)&1)){
              lst.emplace_back(i);
            }
            if(appear == 2 && s[i] && ((u[i] >> bit)&1)){
              lst.emplace_back(i);
            }
          }
          ll p = 0;
          rep(j, n){
            if(appear == 1 && t[j] && ((v[j] >> bit)&1)){
              ans2[bit][lst[p%SZ(lst)]][j] = 1;
              p++;
            }
            if(appear == 2 && !t[j] && !((v[j] >> bit)&1)){
              ans2[bit][lst[p%SZ(lst)]][j] = 0;
              p++;
            }
          }
        }
        rep(i, n){
          rep(j, n){
            if(ans2[bit][i][j] == 2){
              ans2[bit][i][j] = appear == 1 ? 0 : 1;
            }
          }
        }
      }
    }else if(umeflg == 1){
      int appear = 0;
      rep(i, n){
        rep(j, n){
          if(ans2[bit][i][j] == 0){
            appear |= 1;
          }
          if(ans2[bit][i][j] == 1){
            appear |= 2;
          }
        }
      }
      if(appear == 3){
        rep(j, n){
          if(!t[j] && !((v[j] >> bit)&1)){
            rep(i, n){
              ans2[bit][i][j] = 0;
            }
          }
          if(t[j] && ((v[j] >> bit)&1)){
            rep(i, n){
              ans2[bit][i][j] = 1;
            }
          }
        }
      }else{
        bool f = 0;
        rep(j, n){
          if(appear == 1 && t[j] && ((v[j] >> bit)&1)){
            f = 1;
            rep(i, n){
              ans2[bit][i][j] = 1;
            }
          }
          if(appear == 2 && !t[j] && !((v[j] >> bit)&1)){
            f = 1;
            rep(i, n){
              ans2[bit][i][j] = 0;
            }
          }
        }
        if(f){
          rep(j, n){
            if(!t[j] && !((v[j] >> bit)&1)){
              rep(i, n){
                ans2[bit][i][j] = 0;
              }
            }
            if(t[j] && ((v[j] >> bit)&1)){
              rep(i, n){
                ans2[bit][i][j] = 1;
              }
            }
          }
        }else{
          vll lst;
          rep(j, n){
            if(appear == 1 && !t[j] && !((v[j] >> bit)&1)){
              lst.emplace_back(j);
            }
            if(appear == 2 && t[j] && ((v[j] >> bit)&1)){
              lst.emplace_back(j);
            }
          }
          ll p = 0;
          rep(i, n){
            if(appear == 1 && s[i] && ((u[i] >> bit)&1)){
              ans2[bit][i][lst[p%SZ(lst)]] = 1;
              p++;
            }
            if(appear == 2 && !s[i] && !((u[i] >> bit)&1)){
              ans2[bit][i][lst[p%SZ(lst)]] = 0;
              p++;
            }
          }
        }
        rep(i, n){
          rep(j, n){
            if(ans2[bit][i][j] == 2){
              ans2[bit][i][j] = appear == 1 ? 0 : 1;
            }
          }
        }
      }
    }else{
      ll ume = 2;
      rep(i, n){
        rep(j, n){
          if(ans2[bit][i][j] == 1){
            ume = 0;
          }
          if(ans2[bit][i][j] == 0){
            ume = 1;
          }
        }
      }
      rep(i, n){
        rep(j, n){
          if(ans2[bit][i][j] == 2){
            ans2[bit][i][j] = ume;
          }
        }
      }
    }
    
    // check
    rep(i, n){
      rep(j, n){
        if(ans2[bit][i][j] == 2){
          return 22;
        }
      }
    }
    rep(i, n){
      bool f;
      if(s[i]){
        if((u[i] >> bit)&1){
          f = 0;
          rep(j, n){
            if(ans2[bit][i][j] == 1){
              f = 1;
            }
          }
        }else{
          f = 1;
          rep(j, n){
            if(ans2[bit][i][j] == 1){
              f = 0;
            }
          }
        }
      }else{
        if((u[i] >> bit)&1){
          f = 1;
          rep(j, n){
            if(ans2[bit][i][j] == 0){
              f = 0;
            }
          }
        }else{
          f = 0;
          rep(j, n){
            if(ans2[bit][i][j] == 0){
              f = 1;
            }
          }
        }
      }
      if(!f) Pr();
    }
    rep(j, n){
      bool f;
      if(t[j]){
        if((v[j] >> bit)&1){
          f = 0;
          rep(i, n){
            if(ans2[bit][i][j] == 1){
              f = 1;
            }
          }
        }else{
          f = 1;
          rep(i, n){
            if(ans2[bit][i][j] == 1){
              f = 0;
            }
          }
        }
      }else{
        if((v[j] >> bit)&1){
          f = 1;
          rep(i, n){
            if(ans2[bit][i][j] == 0){
              f = 0;
            }
          }
        }else{
          f = 0;
          rep(i, n){
            if(ans2[bit][i][j] == 0){
              f = 1;
            }
          }
        }
      }
      if(!f) Pr();
    }
    
    rep(i, n){
      rep(j, n){
        ans[i][j] += ans2[bit][i][j] << bit;
      }
    }
  }
  rep(i, n) print(ans[i]);
}
