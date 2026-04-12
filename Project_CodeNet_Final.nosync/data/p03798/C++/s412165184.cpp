#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
typedef int64_t ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);

bool solve(const string s, vector<char>& ans) {
  int n = s.size();  
  for (int i = 1; i < n - 1; i++) {
    if ((ans[i] == 'S' && s[i] == 'o') || (ans[i] == 'W' && s[i] == 'x')) {
      ans[i+1] = ans[i-1];
    }
    if ((ans[i] == 'S' && s[i] == 'x') || (ans[i] == 'W' && s[i] == 'o')) {
      if (ans[i-1] == 'W') ans[i+1] = 'S';
      if (ans[i-1] == 'S') ans[i+1] = 'W';
    }
  }

  if ((ans[n-1] == 'S' && s[n-1] == 'o') || (ans[n-1] == 'W' && s[n-1] == 'x')) {
    if (ans[n-2] != ans[0]) return false;
  }

  if (ans[0] == 'S' && s[0] == 'o' || (ans[0] == 'W' && s[0] == 'x')) {
    if (ans[n-1] != ans[1]) return false;
  }

  if ((ans[n-1] == 'S' && s[n-1] == 'x') || (ans[n-1] == 'W' && s[n-1] == 'o')) {
    if (ans[n-2] == ans[0]) return false;
  }

  if ((ans[0] == 'S' && s[0] == 'x') || (ans[0] == 'W' && s[0] == 'o')) {
    if (ans[n-1] == ans[1]) return false;
  }

  return true;
}

void print_vec(const vector<char> ans) {
  for (auto c : ans) {
    printf("%c", c);
  }
  printf("\n");
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<char> ans(n);
  ans[0] = 'S';
  ans[1] = 'S';
  if (solve(s, ans)) {
    print_vec(ans);
    return 0;
  }

  ans[0] = 'S';
  ans[1] = 'W';
  if (solve(s, ans)) {
    print_vec(ans);
    return 0;
  }

  ans[0] = 'W';
  ans[1] = 'S';
  if (solve(s, ans)) {
    print_vec(ans);
    return 0;
  }

  ans[0] = 'W';
  ans[1] = 'W';
  if (solve(s, ans)) {
    print_vec(ans);
    return 0;
  }
    
  puts("-1");
  
  return 0;
}
