#include <bits/stdc++.h>
using namespace std;

int n;
string s, sw = "WS";
int memo[100005] = {0};
bool ans = 0;

void solve(int x);

int main() {
  cin >> n >> s;
  s += s[0];
  s += s[1];
  for(int i = 0; i < n; ++i) memo[i] = -1;
  memo[n + 1] = memo[n] = memo[0] = memo[1] = memo[2] = 1;
  // SSS or WWW
  if(s[1] == 'o')
    solve(0);
  else
    solve(1);
  // WSW or SWS
  memo[n + 1] = memo[1] = 1;
  memo[n] = memo[0] = memo[2] = 0;
  if(s[1] == 'o')
    solve(0);
  else
    solve(1);
  // SSW or WWS
  memo[n + 1] = memo[n] = memo[0] = memo[1] = 1;
  memo[2] = 0;
  if(s[1] == 'o')
    solve(1);
  else
    solve(0);
  // SWW or WSS
  memo[n + 1] = memo[2] = memo[1] = 1;
  memo[n] = memo[0] = 0;
  if(s[1] == 'o')
    solve(1);
  else
    solve(0);
  if(!ans) cout << -1 << endl;
  return 0;
}

void solve(int x) {
  if(ans) return;
  ans = 1;
  for(int i = 2; i <= n; ++i) {
    if(i >= n - 1) {
      if(((s[i] == 'o') ^ x) == memo[i])
        ans &= (memo[i - 1] == memo[i + 1]);
      else
        ans &= (1 - memo[i - 1] == memo[i + 1]);
    }
    if(((s[i] == 'o') ^ x) == memo[i])
      memo[i + 1] = memo[i - 1];
    else
      memo[i + 1] = 1 - memo[i - 1];
  }
  if(!ans) return;
  for(int i = 0; i < n; ++i) cout << sw[memo[i] ^ x];
  cout << endl;
}