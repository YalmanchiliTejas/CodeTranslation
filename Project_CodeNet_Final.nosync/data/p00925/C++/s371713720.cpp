#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define RREP(i, n) RFOR(i, n, 0)
#define MFOR(i, m) for(auto i=(m).begin();i!=(m).end();i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())

typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1 << 30;

template<typename T>
void printv(vector<T> const& s) {
  REP(i, SZ(s)) {
    cout << s[i] << " ";
  }
  cout << endl;
}

bool m(string s, int result) {
  vi v;
  v.pb(s[0] - '0');
  char op;
  FOR(i, 1, SZ(s)) {
    if(i%2) {
      op = s[i];
    } else {
      if(op == '*') {
        v[SZ(v)-1] *= s[i] - '0';
      } else {
        v.pb(s[i] - '0');
      }
    }
  }
  int res = 0;
  REP(i, SZ(v)) {
    res += v[i];
  }

  return res == result;
}

bool l(string s, int result) {
  char op;
  int res = s[0] - '0';
  FOR(i, 1, SZ(s)) {
    if(i % 2) {
      op = s[i];
    } else {
      if(op == '+') {
        res += s[i] - '0';
      } else {
        res *= s[i] - '0';
      }
    }
  }
  return res == result;
}

int main () {
  cin.tie(0);
  cout << setprecision(10);

  string s; cin >> s;
  int result; cin >> result;

  bool M = m(s, result);
  bool L = l(s, result);
  if(M && L) {
    cout << "U" << endl;
  } else if(M) {
    cout << "M" << endl;
  } else if(L) {
    cout << "L" << endl;
  } else {
    cout << "I" << endl;
  }
}


