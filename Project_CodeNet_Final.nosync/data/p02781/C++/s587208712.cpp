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
string alph("abcdefghijklmnopqrstuvwxyz"), n, s;
ll cnt, ans, a, b, c, d, tmp, m, h, w, x, y, sum, k, q;
ll dp[1000][1000];
map<string, ll> mp;

ll comb(ll nn, ll k) {
  if (nn < k) return 0;
  if (dp[nn][k] != 0) return dp[nn][k];
  if (k == 0) return dp[nn][k] = 1;
  if (nn == k) return dp[nn][k] = 1;
  return dp[nn][k] = comb(nn - 1, k - 1) + comb(nn - 1, k);
}

void dfs(ll i, ll j, int fl) {
  if (i > Size(n) || j > k) return;
  if (i != 0) {
    if ((n[i] - '0') == 0)
      dfs(i + 1, j, 0);
    else
      dfs(i + 1, j, 1);
  }
  ll now;
  rrep(z, 1, 10) {
    if (fl == 1) {
      dfs(i + 1, j + 1, 1);
    } else {
      if ((n[i] - '0') < z) continue;
      if ((n[i] - '0') == z)
        now = 0;
      else
        now = 1;
      dfs(i + 1, j + 1, now);
    }
  }
  if (j == k && i == Size(n)) {
    ans++;
    // Cout(s);
  }
}

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  if (Size(n) < k) {
    Cout(0);
    return 0;
  }
  ll kakeru = 1;
  rep(i, k) kakeru *= 9;
  rrep(i, k, Size(n)) {
    if (i < k) continue;
    ans += max(comb(i - 1, k - 1), 1LL) * kakeru;
  }
  vector<ll> p(9);
  rrep(zz, 1, 10) {
    rrep(zzz, 1, 10) {
      rrep(zzzz, 1, 10) {
        p[0] = zz;
        p[1] = zzz;
        p[2] = zzzz;
        s = to_string(p[0]);
        if (k >= 2) s += to_string(p[1]);
        if (k >= 3) s += to_string(p[2]);
        if (mp[s]) continue;
        mp[s] = 1;
        if (p[0] > (n[0] - '0')) continue;
        if (k == 1)
          ans++;
        else {
          rrep(i, 1, Size(n)) {
            if (k == 3) {
              rrep(j, i + 1, Size(n)) {
                int ok = 0;
                rrep(z, 0, Size(n)) {
                  if (z == 0) {
                    if ((s[0] - '0') == (n[z] - '0')) continue;
                    if ((s[0] - '0') < (n[z] - '0')) {
                      break;
                    } else {
                      ok = 1;
                      break;
                    }
                  } else if (z == i) {
                    if ((s[1] - '0') == (n[z] - '0')) continue;
                    if ((s[1] - '0') < (n[z] - '0')) {
                      break;
                    } else {
                      ok = 1;
                      break;
                    }
                  } else if (z == j) {
                    if ((s[2] - '0') == (n[z] - '0')) continue;
                    if ((s[2] - '0') < (n[z] - '0')) {
                      break;
                    } else {
                      ok = 1;
                      break;
                    }
                  } else {
                    if (0 == (n[z] - '0')) continue;
                    if (0 < (n[z] - '0')) {
                      break;
                    } else {
                      ok = 1;
                      break;
                    }
                  }
                }
                // 0,i,j
                // cout << a << " " << b << "\n";
                if (!ok) ans++;
              }
            } else if (k == 2) {
              int ok = 0;
              rrep(z, 0, Size(n)) {
                if (z == 0) {
                  if ((s[0] - '0') == (n[z] - '0')) continue;
                  if ((s[0] - '0') < (n[z] - '0')) {
                    break;
                  } else {
                    ok = 1;
                    break;
                  }
                } else if (z == i) {
                  // cout << p[1] << " " << n[z] << "\n";
                  if ((s[1] - '0') == (n[z] - '0')) continue;
                  if ((s[1] - '0') < (n[z] - '0')) {
                    break;
                  } else {
                    ok = 1;
                    break;
                  }
                } else {
                  if (0 == (n[z] - '0')) continue;
                  if (0 < (n[z] - '0')) {
                    break;
                  } else {
                    ok = 1;
                    break;
                  }
                }
              }
              if (!ok) ans++;
            }
          }
        }
      }
    }
  }
  Cout(ans);
  return 0;
}