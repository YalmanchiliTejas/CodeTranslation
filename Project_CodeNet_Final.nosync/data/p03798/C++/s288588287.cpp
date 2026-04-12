#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define pb push_back
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define dep(i, a, n) for(int i = (a); i >= (n); i--)
#define mod (ll)(1e9+7)
#define int ll

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int n;
string s;

bool solve(string ans) {
  rep(i, 1, n) {
    if(ans[i] == 'S') {
      if(s[i] == 'o') {
        ans += "S";
      }else {
        ans += "W";
      }
    }else {
      if(s[i] == 'o') {
        ans += "W";
      }else {
        ans += "S";
      }
    }
    if(ans[i - 1] == 'W') ans[i + 1] = ans[i + 1] == 'W' ? 'S' : 'W';
  }
  if(ans[n] == ans[0]) {
    ans.pop_back();
    if(ans[0] == 'S') {
      if(s[0] == 'o') {
        if(ans[n - 1] != ans[1]) return false;
      }else {
        if(ans[n - 1] == ans[1]) return false;
      }
    }else {
      if(s[0] == 'o') {
        if(ans[n - 1] == ans[1]) return false;
      }else {
        if(ans[n - 1] != ans[1]) return false;
      }
    }
    cout << ans << endl;
    return true;
  }

  return false;
}

signed main() {
  cin >> n >> s;

  if(solve("SS")) return 0;
  if(solve("SW")) return 0;
  if(solve("WW")) return 0;;
  if(solve("WS")) return 0;

  cout << -1 << endl;
}
