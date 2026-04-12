#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=(b-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)

template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }

constexpr ll mod = 998244353;
/*
void solve(){
  string s; cin >> s; int n = s.size();
  bool flg = true;
  FOR(i,0,n/2){
    if(s[i] != s[n/2-1-i]) flg = false;
  }
  FOR(i,0,n/2){
    if(s[n/2+1+i] != s[n-1-i]) flg = false;
  }
  if(flg) cout << "Yes";
  else cout << "No";
}
*/

ll dp[3005][3005][3];
void solve(){
  int n, s;cin >> n >> s;
  vector<int> a(n+1);
  RPT(i,0,n) cin  >> a[i];
  RPT(i,0,n+1)RPT(j,0,s+1) RPT(k,0,3) dp[i][j][k] = 0;
  dp[0][0][0] = 1;
  FOR(i,0,n){
    FOR(j,0,s+1){
      (dp[i+1][j][0] += dp[i][j][0]) %= mod;
      (dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
      (dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= mod;
      if(j+a[i]<=s){
        (dp[i+1][j+a[i]][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
        (dp[i+1][j+a[i]][2] += dp[i][j][0] + dp[i][j][1]) %= mod;
      }
    }
  }/*
  FOR(i,0,n+1){
    printf("%02d:",i);
    FOR(j,0,s+1){
      printf("%03d,%03d,%03d  ",dp[i][j][0], dp[i][j][1], dp[i][j][2]);
    }
    printf("\n");
  }*/
  cout << dp[n][s][2] << endl;
}


int main(void){
  solve();
  return 0;
}