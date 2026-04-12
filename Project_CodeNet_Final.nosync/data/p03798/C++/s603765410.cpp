#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i,s,n) for(ll i = (s); i < (n); i++)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define repR(i,s,n) for(ll i = (n-1); i >= (s); i--)
#define repR0(i,n) repR(i,0,n)
#define repR1(i,n) repR(i,1,n+1)

#define BR "\n"
#define SP " "
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << SP; } cout << BR;
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << BR;
#define fcout cout << fixed << setprecision(18)

int N;
string s;
string ans;
bool check(string init) {
  ans = s;
  ans[0] = init[0];
  ans[1] = init[1];
  rep(i, 2, N) {
    if (s[i - 1] == 'o') {
      if (ans[i - 1] == 'S') ans[i] = ans[i - 2];
      else ans[i] = (ans[i - 2] == 'S')? 'W': 'S';
    } else {
      if (ans[i - 1] == 'W') ans[i] = ans[i - 2];
      else ans[i] = (ans[i - 2] == 'S')? 'W': 'S';
    }
  }
  if (ans[N - 2] == ans[0]) {
    if (ans[N - 1] == 'S' && s[N - 1] == 'x') return false;
    if (ans[N - 1] == 'W' && s[N - 1] == 'o') return false;
  }
  if (ans[N - 2] != ans[0]) {
    if (ans[N - 1] == 'S' && s[N - 1] == 'o') return false;
    if (ans[N - 1] == 'W' && s[N - 1] == 'x') return false;
  }
  if (ans[N - 1] == ans[1]) {
    if (ans[0] == 'S' && s[0] == 'x') return false;
    if (ans[0] == 'W' && s[0] == 'o') return false;
  }
  if (ans[N - 1] != ans[1]) {
    if (ans[0] == 'S' && s[0] == 'o') return false;
    if (ans[0] == 'W' && s[0] == 'x') return false;
  }
  return true;
}
int main() {
  cin >> N  >> s;
  if (check("SS") || check("SW") || check("WS") || check("WW")) {
    cout << ans << BR;
  } else {
    cout << "-1" << BR;
  }
  return 0;
}