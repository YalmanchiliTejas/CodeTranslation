#ifdef DEBUG_IS_VALID
#define DEB 1 
#define _LIBCPP_DEBUG 0
#else
#define DEB 0
#define NDEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(long long i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i, x, n) for(long long i = x; i >= n; i--)
#define rrep(i, n) RREP(i,n,0)
#define pb push_back
#define fi first
#define se second
#pragma GCC optimize ("-O3")

using namespace std;

#define DUMPOUT cout
#define dump(...) if(DEB) DUMPOUT<<"  "<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl<<"    "; if(DEB) dump_func(__VA_ARGS__)
template<typename T1,typename T2>ostream& operator << (ostream& os, pair<T1,T2> p){cout << "(" << p.first << ", " << p.second << ")"; return os;}
template<typename T>ostream& operator << (ostream& os, vector<T>& vec) { os << "{"; for (int i = 0; i<vec.size(); i++) os << vec[i] << (i + 1 == vec.size() ? "" : ", "); os << "}"; return os; }
template<typename T>ostream& operator << (ostream& os, set<T>& st){cout << "{"; for(auto itr = st.begin(); itr != st.end(); itr++) cout << *itr << (next(itr)!=st.end() ? ", " : ""); cout << "}"; return os;}
template<typename T1,typename T2>ostream& operator << (ostream& os, map<T1,T2> mp){cout << "{"; for(auto itr = mp.begin(); itr != mp.end(); itr++) cout << "(" << (itr->first) << ", " << (itr->second) << ")" << (next(itr)!=mp.end() ? "," : ""); cout << "}"; return os; }

void dump_func(){DUMPOUT << endl;}
template <class Head, class... Tail>void dump_func(Head&& head, Tail&&... tail){ DUMPOUT << head; if (sizeof...(Tail) == 0) { DUMPOUT << " "; } else { DUMPOUT << ", "; } dump_func(std::move(tail)...);}
template<class T> inline bool chmax(T& a,T const& b){if(a>=b) return false; a=b; return true;}
template<class T> inline bool chmin(T& a,T const& b){if(a<=b) return false; a=b; return true;}

using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vp = vector<Pl>;
using vvp = vector<vp>;

const int INF = 1<<29;
const long long LINF=1LL<<59;

// ll comb(ll n, ll k){
//   if(n <= k) return 1LL;
//   ll res = 1;
//   ll sz = k;
//   rep(i,sz){
//     res *= n;
//     n--;
//   }
//   rep(i,sz){
//     res /= k;
//     k--;
//   }
//   return res;
// }

// ll sol(string N, ll K){
//   ll sz = N.size();
//   ll res = 0;
//   if(K == 1){
//     res += 9*(sz-1);
//     res += int(N[0] - '0');
//     dump(res);
//     return res;
//   }

//   // if(sz-1 >= K) res += comb(sz-1, K) * pow(9LL, K);
//   dump(res);
//   res += (ll(N[0] - '0') - 1) * comb(sz-1, K-1) * pow(9LL, min(K-1, sz-1));
//   dump(res);
//   string nxt = N.substr(1, sz-1);
//   dump(res);
//   return res + sol(nxt, K-1);
// }

void solve(string N, long long K){
  // cout << sol(N, K) << endl;
  ll sz = N.size();
  ll ans = 0;
  vector<vvl> dp(sz+1, vvl(K+1, vl(2)));
  dp[0][0][0] = 1;
  rep(i,sz) {
    rep(k, K+1){
      dp[i+1][k][1] += dp[i][k][1]; // 0
      if(k+1<=K) dp[i+1][k+1][1] += dp[i][k][1] * 9; // 1-9
      if(N[i] != '0') dp[i+1][k][1] += dp[i][k][0]; // 0 
      else dp[i+1][k][0] += dp[i][k][0];
      // 1- less than N[i]
      if(k+1<= K && N[i]!='0') dp[i+1][k+1][1] += dp[i][k][0] * (ll(N[i]-'0')-1);
      // N[i]
      if(N[i] != '0' && k+1<=K) dp[i+1][k+1][0] += dp[i][k][0];
    }
  }
  cout << dp[sz][K][1]+dp[sz][K][0] << endl;
}

int main(){
  std::cout << std::fixed << std::setprecision(15);
  string N;
  cin >> N;
  long long K;
  cin >> K;
  solve(N, K);
  return 0;
}
