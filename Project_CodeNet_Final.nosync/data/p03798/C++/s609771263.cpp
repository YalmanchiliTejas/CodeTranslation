// review
#include <iostream>

using namespace std;

bool candidate[2] = {true, false};

bool state[100010];
int n;
string s;

bool next(int pos) {
  return (s[pos-1] == 'o') ^ state[pos-1] ^ state[pos-2];
}

bool dfs(int pos) {
  if (pos == n + 2) {
    if (state[0] == state[n] && state[1] == state[n+1]) {
      for (int i=0;i<n;i++) {
        if (state[i]) {
          cout << 'S';
        } else {
          cout << 'W';
        }
      }
      cout << endl;
      return true;
    }
    return false;
  }
  state[pos] = next(pos);
  return dfs(pos+1);
}

void solve() {
  s = s + s[0] + s[1];
  for (int i=0;i<2;i++) {
    for (int j=0;j<2;j++) {
      state[0] = candidate[i];
      state[1] = candidate[j];
      if (dfs(2)) {
        return;
      }
    }
  }
  cout << -1 << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s;
  solve();
}
