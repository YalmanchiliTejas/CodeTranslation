#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP2(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define REPR(i, n) for (int i = (n)-1; i >= 0; --i)
#define REPR2(i, m, n) for (int i = (n)-1; i >= (m); --i)
#define REPx(x, a) for(auto x : a)
#define ALL(a) a.begin(), a.end()
#define SORT(a) sort(ALL(a))
#define SORTR(a) sort(ALL(a), greater<int>())
#define REVERSE(a) reverse(ALL(a))
#define bit_search(bit, n) REP(bit, 1<<(n))
#define bit_check(bit, i) (bit>>(i)) & 1
#define setpre(n) fixed << setprecision((n))
#define UNIQUE(a) do {SORT(a); (a).erase(unique(ALL(a)), (a).end());} while(0)
#define MAX(a) *max_element(ALL(a))
#define MIN(a) *min_element(ALL(a))
#define bisect_left(a, x) lower_bound(ALL(a), (x)) - a.begin()
#define bisect_right(a, x) upper_bound(ALL(a), (x)) - a.begin()
#define INPUT(a) REP(i, a.size()) cin >> a[i];
#define INPUTP(a) REP(i, a.size()) cin >> a[i].first >> a[i].second;
#define ENDL cout << endl;
using namespace std;
using ll = long long;
using ld = long double;
using PII = pair<int, int>;
using VPII = vector<PII>;
using PLL = pair<ll, ll>;
using VPLL = vector<PLL>;
using VI = vector<int>;
using VVI = vector<VI>;
using Vll = vector<ll>;
using VVll = vector<Vll>;
using VC = vector<char>;
using VS = vector<string>;
using VB = vector<bool>;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

bool check(auto s, auto ans, auto idx, auto N)
{
  int l, r;
  if (idx == N-1) {l = 0; r = N-2;}
  else if (idx == 0) {l = 1; r = N-1;}
  if (s[idx] == 'o')
  {
    if (ans[idx] == 'S')
    {
      if (ans[l] != ans[r]) return false;
      else return true;
    }
    else if (ans[idx] == 'W')
    {
      if (ans[l] == ans[r]) return false;
      else return true;
    }
  }
  else if (s[idx] == 'x')
  {
    if (ans[idx] == 'S')
    {
      if (ans[l] == ans[r]) return false;
      else return true;
    }
    else if (ans[idx] == 'W')
    {
      if (ans[l] != ans[r]) return false;
      else return true;
    }
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  string s;
  cin >> s;
  VC ans(N);
  ans[0] = 'S';
  ans[1] = 'S';
  REP2(i, 1, N-1)
  {
    if (s[i] == 'o')
    {
      if (ans[i] == 'S') ans[i+1] = ans[i-1];
      else if (ans[i] == 'W')
      {
        if (ans[i-1] == 'S') ans[i+1] = 'W';
        else if (ans[i-1] == 'W') ans[i+1] = 'S';
      }
    }
    else if (s[i] == 'x')
    {
      if (ans[i] == 'S')
      {
        if (ans[i-1] == 'S') ans[i+1] = 'W';
        else if (ans[i-1] == 'W') ans[i+1] = 'S';
      }
      else if (ans[i] == 'W') ans[i+1] = ans[i-1];
    }
  }
  if (check(s, ans, 0, N) && check(s, ans, N-1, N))
  {
    REP(i, N) cout << ans[i];
    ENDL
    return 0;
  }
  ans[0] = 'S';
  ans[1] = 'W';
  REP2(i, 1, N-1)
  {
    if (s[i] == 'o')
    {
      if (ans[i] == 'S') ans[i+1] = ans[i-1];
      else if (ans[i] == 'W')
      {
        if (ans[i-1] == 'S') ans[i+1] = 'W';
        else if (ans[i-1] == 'W') ans[i+1] = 'S';
      }
    }
    else if (s[i] == 'x')
    {
      if (ans[i] == 'S')
      {
        if (ans[i-1] == 'S') ans[i+1] = 'W';
        else if (ans[i-1] == 'W') ans[i+1] = 'S';
      }
      else if (ans[i] == 'W') ans[i+1] = ans[i-1];
    }
  }
  if (check(s, ans, 0, N) && check(s, ans, N-1, N))
  {
    REP(i, N) cout << ans[i];
    ENDL
    return 0;
  }
  ans[0] = 'W';
  ans[1] = 'W';
  REP2(i, 1, N-1)
  {
    if (s[i] == 'o')
    {
      if (ans[i] == 'S') ans[i+1] = ans[i-1];
      else if (ans[i] == 'W')
      {
        if (ans[i-1] == 'S') ans[i+1] = 'W';
        else if (ans[i-1] == 'W') ans[i+1] = 'S';
      }
    }
    else if (s[i] == 'x')
    {
      if (ans[i] == 'S')
      {
        if (ans[i-1] == 'S') ans[i+1] = 'W';
        else if (ans[i-1] == 'W') ans[i+1] = 'S';
      }
      else if (ans[i] == 'W') ans[i+1] = ans[i-1];
    }
  }
  if (check(s, ans, 0, N) && check(s, ans, N-1, N))
  {
    REP(i, N) cout << ans[i];
    ENDL
    return 0;
  }
  ans[0] = 'W';
  ans[1] = 'S';
  REP2(i, 1, N-1)
  {
    if (s[i] == 'o')
    {
      if (ans[i] == 'S') ans[i+1] = ans[i-1];
      else if (ans[i] == 'W')
      {
        if (ans[i-1] == 'S') ans[i+1] = 'W';
        else if (ans[i-1] == 'W') ans[i+1] = 'S';
      }
    }
    else if (s[i] == 'x')
    {
      if (ans[i] == 'S')
      {
        if (ans[i-1] == 'S') ans[i+1] = 'W';
        else if (ans[i-1] == 'W') ans[i+1] = 'S';
      }
      else if (ans[i] == 'W') ans[i+1] = ans[i-1];
    }
  }
  if (check(s, ans, 0, N) && check(s, ans, N-1, N))
  {
    REP(i, N) cout << ans[i];
    ENDL
    return 0;
  }
  cout << -1 << endl;

  return 0;
}