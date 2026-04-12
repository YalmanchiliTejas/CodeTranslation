#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
static const int INF (1<<30);

int main() {
  int N; cin >> N;
  string S; cin >> S;
  S = 'z' + S;

  vector<char> ans(N+2);
  bool done = false;

  // first sheep last sheep
  ans[0] = 'S';
  ans[1] = 'S';
  for (int i = 1; i <= N; i++) {
    if (ans[i] == 'S') {
      if (S[i] == 'o') {
        ans[i+1] = ans[i-1];
      } else {
        if (ans[i-1] == 'S') ans[i+1] = 'W';
        else ans[i+1] = 'S';
      }
    } else {
      if (S[i] == 'x') {
        ans[i+1] = ans[i-1];
      } else {
        if (ans[i-1] == 'S') ans[i+1] = 'W';
        else ans[i+1] = 'S';
      }
    }
  }
  if (ans[0] == ans[N] && ans[1] == ans[N+1]) done = true;


  if (!done) {
    // first sheep last wolf
    ans[0] = 'W';
    ans[1] = 'S';
    for (int i = 1; i <= N; i++) {
      if (ans[i] == 'S') {
        if (S[i] == 'o') {
          ans[i+1] = ans[i-1];
        } else {
          if (ans[i-1] == 'S') ans[i+1] = 'W';
          else ans[i+1] = 'S';
        }
      } else {
        if (S[i] == 'x') {
          ans[i+1] = ans[i-1];
        } else {
          if (ans[i-1] == 'S') ans[i+1] = 'W';
          else ans[i+1] = 'S';
        }
      }
    }
    if (ans[0] == ans[N] && ans[1] == ans[N+1]) done = true;
  }

  if (!done) {
    // first wolf last wolf
    ans[0] = 'W';
    ans[1] = 'W';
    for (int i = 1; i <= N; i++) {
      if (ans[i] == 'S') {
        if (S[i] == 'o') {
          ans[i+1] = ans[i-1];
        } else {
          if (ans[i-1] == 'S') ans[i+1] = 'W';
          else ans[i+1] = 'S';
        }
      } else {
        if (S[i] == 'x') {
          ans[i+1] = ans[i-1];
        } else {
          if (ans[i-1] == 'S') ans[i+1] = 'W';
          else ans[i+1] = 'S';
        }
      }
    }
    if (ans[0] == ans[N] && ans[1] == ans[N+1]) done = true;
  }

  if (!done) {
    // first wolf last sheep
    ans[0] = 'S';
    ans[1] = 'W';
    for (int i = 1; i <= N; i++) {
      if (ans[i] == 'S') {
        if (S[i] == 'o') {
          ans[i+1] = ans[i-1];
        } else {
          if (ans[i-1] == 'S') ans[i+1] = 'W';
          else ans[i+1] = 'S';
        }
      } else {
        if (S[i] == 'x') {
          ans[i+1] = ans[i-1];
        } else {
          if (ans[i-1] == 'S') ans[i+1] = 'W';
          else ans[i+1] = 'S';
        }
      }
    }
    if (ans[0] == ans[N] && ans[1] == ans[N+1]) done = true;
  }


  if (done) {
    ans.erase(ans.begin());
    ans.pop_back();
    for (auto x : ans) cout << x;
  } else {
    cout << -1 << endl;
  }

  return 0;
}