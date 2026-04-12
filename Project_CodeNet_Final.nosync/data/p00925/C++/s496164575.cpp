#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define ALL(a) (a).begin(),(a).end()
#define DEBUG(a) "(" << #a << ": " << (a) << ")"

template<typename T>
void chmin(T &x, T y) { x = min(x, y); }

template<typename T>
void chmax(T &x, T y) { x = max(x, y); }

typedef long long int lli;
typedef long double ld;
typedef tuple<int,int> P;

const int INF = INT_MAX/2 - 1;
const double EPS = 1e-14;
const bool OREWA_MOU_DAMEDA = true;
const int dx[4] = {0, 1, 0, -1}; // {-1,  0,  1, -1, 1, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0}; // {-1, -1, -1,  0, 0,  1, 1, 1};

string str; unsigned int p;

lli Digit() {
  if (isdigit(str[p])) { return str[p++] - '0'; }
  throw OREWA_MOU_DAMEDA;
}

lli Factor() {
  lli lhs = Digit();
  if (p < str.size() && str[p] == '*') {
    p++; // read *
    lli rhs = Factor();
    return lhs * rhs;
  }
  return lhs;
}

lli Expr() {
  lli lhs = Factor();
  if (p < str.size() && str[p] == '+') {
    p++; // read +
    lli rhs = Expr();
    return lhs + rhs;
  }
  return lhs;
}

lli calc_left2right(const string &expr) {
  lli ans = expr[0] - '0';
  REP(i, (expr.size() - 1) / 2) {
    if (expr[2 * i + 1] == '+') {
      ans += expr[2 * i + 2] - '0';
    }
    else if (expr[2 * i + 1] == '*') {
      ans *= expr[2 * i + 2] - '0';
    }
    else {
      throw OREWA_MOU_DAMEDA;
    }
  }
  return ans;
}

char solve(string expr, lli ans) {
  str = expr, p = 0;
  lli m = Expr();
  lli l = calc_left2right(expr);
  if (ans == m && ans == l) { return 'U'; }
  if (ans == m) { return 'M'; }
  if (ans == l) { return 'L'; }
  return 'I';
}

int main() {
  cout << fixed << setprecision(10);
  string str;
  lli ans;
  cin >> str >> ans;
  cout << solve(str, ans) << endl;
  return 0;
}