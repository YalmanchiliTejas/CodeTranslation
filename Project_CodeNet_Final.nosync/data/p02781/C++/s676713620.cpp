#pragma target("avx")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef unordered_map<ll, ll> U_MAP;
typedef priority_queue<ll> pq;
typedef priority_queue<ll, vector<ll>, greater<ll>> rpq;
const int INF = 1e9, MOD = 1e9 + 7, ohara = 1e6 + 10;
const ll LINF = 1e18;

#define rep(i, n) for (ll(i) = 0; (i) < (int)(n); (i)++)
#define rrep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrrep(i, a, b) for (ll i = (a); i >= (b); i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout << (x) << endl
#define doublecout(a) cout << fixed << setprecision(15) << a << endl;
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

//------ Believe yourself as a genius!!!!!! ------

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
// int dy[]={-1,0,1,-1,1,-1,0,1};int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"), s;
ll n, cnt, ans, a, b, c, d, tmp, m, h, w, x, y, sum, k, q;
ll dp[150][10][3];

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  cin >> s >> k;
  dp[0][0][0] = 1;
  rrep(i, 1, Size(s) + 1) {
    rep(j, k + 1) {
      if (i < j) continue;
      // 0を入れる
      if (s[i - 1] == '0') {
        dp[i][j][0] += dp[i - 1][j][0];
        dp[i][j][1] += dp[i - 1][j][1];
      } else {
        // dp[i][j][0] += dp[i - 1][j][0];
        dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][0];
      }

      if (j == 0) continue;
      // 0でないのを入れる
      rrep(in, 1, 10) {
        if (in < (s[i - 1] - '0')) {
          dp[i][j][1] += dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0];
        } else if (in == (s[i - 1] - '0')) {
          dp[i][j][0] += dp[i - 1][j - 1][0];
          dp[i][j][1] += dp[i - 1][j - 1][1];
        } else {
          dp[i][j][1] += dp[i - 1][j - 1][1];
        }
      }
    }
  }
  ans = dp[Size(s)][k][1] + dp[Size(s)][k][0];
  Cout(ans);
  return 0;
}