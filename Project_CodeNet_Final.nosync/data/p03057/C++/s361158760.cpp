#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define unordered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MaxN = 2e5 + 100;
const int Mod = 1e9 + 7;

int dp[MaxN];
int pref_dp[MaxN];

int small_dp[MaxN][2][2];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int N, M;
  string s;
  cin >> N >> M >> s;

  if (count(ALL(s), s[0]) == M) {
    small_dp[1][1][1] = small_dp[1][0][0] = 1;
    for (int len = 2; len <= N; ++len) {
      for (int fst : {0, 1}) {
        // add gut
        small_dp[len][fst][0] =
          (small_dp[len - 1][fst][0] + small_dp[len - 1][fst][1]) % Mod;
        // add no gut
        small_dp[len][fst][1] = small_dp[len - 1][fst][0];
      }
    }

    int ans = 0;
    for (int x : {0, 1}) {
      for (int y : {0, 1}) {
        if (x + y <= 1) {
          ans = (ans + small_dp[N][x][y]) % Mod;
        }
      }
    }
    cout << ans << "\n";
    return 0;
  }

  if (s[0] != s[1]) {
    if (N % 2 == 0) {
      cout << "2\n";
    } else {
      cout << "0\n";
    }
    return 0;
  }

  int min_seg_len = N - 1;
  int cur_len = 0;
  while (s[cur_len] == s[0]) { ++cur_len; }
  min_seg_len = cur_len;
  cur_len = 0;
  for (char ch : s) {
    if (ch == s[0]) {
      ++cur_len;
    } else {
      if (cur_len % 2 == 1) { mini(min_seg_len, cur_len); }
      cur_len = 0;
    }
  }
  //if (cur_len) { mini(min_seg_len, cur_len); }


  int answer = 0;

  dp[0] = pref_dp[2] = 1;

  const int min_jump = 2;
  int max_jump = min_seg_len + 2;
  // jump must be even as well
  if (max_jump % 2 == 1) { --max_jump; }

  debug(min_jump, max_jump);

  for (int len = 1; len <= N; ++len) {
    const int add_from = max(0, len - max_jump);
    const int add_to = len - min_jump;

    if (add_from <= add_to) {
      dp[len] = pref_dp[add_to + 2] - pref_dp[add_from];
      if (dp[len] < 0) { dp[len] += Mod; }
    }

    debug(len, dp[len]);

    pref_dp[len + 2] = (pref_dp[len] + dp[len]) % Mod;
  }

  for (int chain_len = 0; chain_len < N; ++chain_len) {
    const int rem_len = N - chain_len;
    if (2 <= rem_len && rem_len <= max_jump && rem_len % 2 == 0) {
      const int coef = dp[chain_len];
      answer = (answer + (LL)coef * (rem_len )) % Mod;
    }
  }

  cout << answer << "\n";
}

