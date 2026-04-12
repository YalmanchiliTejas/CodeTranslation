#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define MOD 1000000007
#define INF (1LL<<25)     //33554432
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll
//ox
signed main(void)
{
  int n;
  string s;
  cin >> n >> s;

  // 0=W 1=S
  int a[100010] = {0};
  a[0] = 1;
  //cout << s[0] << endl;
  if(s[0] == 'o') {a[n-1] = 0; a[1] = 0;}
  else {a[n-1] = 0; a[1] = 1;}
  FOR(i, 1, n-2) {
    if(a[i] == 1 && s[i] == 'o') a[i+1] = a[i-1];
    else if(a[i] == 1 && s[i] == 'x') a[i+1] = !a[i-1];
    else if(a[i] == 0 && s[i] == 'o') a[i+1] = !a[i-1];
    else if(a[i] == 0 && s[i] == 'x') a[i+1] = a[i-1];
    //cout << a[i+1] << endl;
  }
  bool flag = true;
  if(s[n-2] == 'o') {
    if(a[n-2] == 1 && a[n-3] != a[n-1]) flag = false;
    if(a[n-2] == 0 && a[n-3] == a[n-1]) flag = false;
  } else {
    if(a[n-2] == 1 && a[n-3] == a[n-1]) flag = false;
    if(a[n-2] == 0 && a[n-3] != a[n-1]) flag = false;
  }
  if(s[n-1] == 'o') {
    if(a[n-1] == 1 && a[n-2] != a[0]) flag = false;
    if(a[n-1] == 0 && a[n-2] == a[0]) flag = false;
  } else {
    if(a[n-1] == 1 && a[n-2] == a[0]) flag = false;
    if(a[n-1] == 0 && a[n-2] != a[0]) flag = false;
  }
  //REP(i, n) cout << a[i]; cout << endl;
  if(flag) {
    REP(i, n) {
      if(a[i]) cout << 'S';
      else cout << 'W';
    }
    cout << endl;
    //cout << "a" << endl;
    return 0;
  }

  a[0] = 1;
  if(s[0] == 'o') {a[n-1] = 1; a[1] = 1;}
  else {a[n-1] = 1; a[1] = 0;}
  FOR(i, 1, n-2) {
    if(a[i] == 1 && s[i] == 'o') a[i+1] = a[i-1];
    else if(a[i] == 1 && s[i] == 'x') a[i+1] = !a[i-1];
    else if(a[i] == 0 && s[i] == 'o') a[i+1] = !a[i-1];
    else if(a[i] == 0 && s[i] == 'x') a[i+1] = a[i-1];
  }
  flag = true;
  if(s[n-2] == 'o') {
    if(a[n-2] == 1 && a[n-3] != a[n-1]) flag = false;
    if(a[n-2] == 0 && a[n-3] == a[n-1]) flag = false;
  } else {
    if(a[n-2] == 1 && a[n-3] == a[n-1]) flag = false;
    if(a[n-2] == 0 && a[n-3] != a[n-1]) flag = false;
  }
  if(s[n-1] == 'o') {
    if(a[n-1] == 1 && a[n-2] != a[0]) flag = false;
    if(a[n-1] == 0 && a[n-2] == a[0]) flag = false;
  } else {
    if(a[n-1] == 1 && a[n-2] == a[0]) flag = false;
    if(a[n-1] == 0 && a[n-2] != a[0]) flag = false;
  }
  if(flag) {
    REP(i, n) {
      if(a[i]) cout << 'S';
      else cout << 'W';
    }
    cout << endl;
    //cout << "b" << endl;
    return 0;
  }

  a[0] = 0;
  if(s[0] == 'o') {a[n-1] = 0; a[1] = 1;}
  else {a[n-1] = 0; a[1] = 0;}
  FOR(i, 1, n-2) {
    if(a[i] == 1 && s[i] == 'o') a[i+1] = a[i-1];
    else if(a[i] == 1 && s[i] == 'x') a[i+1] = !a[i-1];
    else if(a[i] == 0 && s[i] == 'o') a[i+1] = !a[i-1];
    else if(a[i] == 0 && s[i] == 'x') a[i+1] = a[i-1];
  }
  flag = true;
  if(s[n-2] == 'o') {
    if(a[n-2] == 1 && a[n-3] != a[n-1]) flag = false;
    if(a[n-2] == 0 && a[n-3] == a[n-1]) flag = false;
  } else {
    if(a[n-2] == 1 && a[n-3] == a[n-1]) flag = false;
    if(a[n-2] == 0 && a[n-3] != a[n-1]) flag = false;
  }
  if(s[n-1] == 'o') {
    if(a[n-1] == 1 && a[n-2] != a[0]) flag = false;
    if(a[n-1] == 0 && a[n-2] == a[0]) flag = false;
  } else {
    if(a[n-1] == 1 && a[n-2] == a[0]) flag = false;
    if(a[n-1] == 0 && a[n-2] != a[0]) flag = false;
  }
  if(flag) {
    REP(i, n) {
      if(a[i]) cout << 'S';
      else cout << 'W';
    }
    cout << endl;
    //cout << "c" << endl;
    return 0;
  }

  a[0] = 0;
  if(s[0] == 'o') {a[n-1] = 1; a[1] = 0;}
  else {a[n-1] = 1; a[1] = 1;}
  FOR(i, 1, n-2) {
    if(a[i] == 1 && s[i] == 'o') a[i+1] = a[i-1];
    else if(a[i] == 1 && s[i] == 'x') a[i+1] = !a[i-1];
    else if(a[i] == 0 && s[i] == 'o') a[i+1] = !a[i-1];
    else if(a[i] == 0 && s[i] == 'x') a[i+1] = a[i-1];
  }
  flag = true;
  if(s[n-2] == 'o') {
    if(a[n-2] == 1 && a[n-3] != a[n-1]) flag = false;
    if(a[n-2] == 0 && a[n-3] == a[n-1]) flag = false;
  } else {
    if(a[n-2] == 1 && a[n-3] == a[n-1]) flag = false;
    if(a[n-2] == 0 && a[n-3] != a[n-1]) flag = false;
  }
  if(s[n-1] == 'o') {
    if(a[n-1] == 1 && a[n-2] != a[0]) flag = false;
    if(a[n-1] == 0 && a[n-2] == a[0]) flag = false;
  } else {
    if(a[n-1] == 1 && a[n-2] == a[0]) flag = false;
    if(a[n-1] == 0 && a[n-2] != a[0]) flag = false;
  }
  if(flag) {
    REP(i, n) {
      if(a[i]) cout << 'S';
      else cout << 'W';
    }
    cout << endl;
    //cout << "d" << endl;
    return 0;
  }

  cout << -1 << endl;
  return 0;
}
