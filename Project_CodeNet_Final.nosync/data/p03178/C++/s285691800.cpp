#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)

#define n_l '\n'
template <typename T, size_t N> int SIZE(const T (&t)[N]) { return N; } template<typename T> int SIZE(const T &t) { return t.size(); } string to_string(const string s, int x1 = 0, int x2 = 1e9) { return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c) { return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1 = 0, int x2 = 1e9) { string t = ""; for (int __iii__ = min(x1, SIZE(b)),  __jjj__ = min(x2, SIZE(b) - 1); __iii__ <= __jjj__; ++__iii__) { t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1 = 0, int x2 = 1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if (l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2 - x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if (e != l) { if (rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else { t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if (l_v_l_v_l == 0) res += n_l; return res; } void dbgm() {;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T) { cout << to_string(H) << " | "; dbgm(T...); }
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cout << endl

const int mod = 1e9 + 7;

int32_t main() {
   ios::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);

   string s;
   int d;
   cin >> s >> d;
   int m = s.length();
   vector <vector <int>> dp(m + 1, vector <int> (d));

   vector <int> prev(d);
   for (int i = 0; i < s[0] - '0'; i++) {
      dp[0][i % d]++;
   }
   prev[(s[0] - '0') % d] += 1;

   for (int i = 1; i < m; i++) {
      for (int j = 0; j < 10; j++) {
         for (int k = 0; k < d; k++) {
            if (j < s[i] - '0') {
               dp[i][(j + k) % d] += (dp[i - 1][k] + prev[k]) % mod;
            } else {
               dp[i][(j + k) % d] += dp[i - 1][k];
            }
            dp[i][(j + k) % d] %= mod;
         }
      }
      vector <int> temp(d);
      int j = s[i] - '0';
      for (int k = 0; k < d; k++) {
         temp[(j + k) % d] += prev[k];
         temp[(j + k) % d] %= mod;
      }
      prev = temp;
   }

   cout << (dp[m - 1][0] + prev[0] - 1 + mod) % mod << '\n';

   return 0;
}