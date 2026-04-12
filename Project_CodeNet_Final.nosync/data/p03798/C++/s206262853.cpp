#include <bits/stdc++.h>

using namespace std;

#define MAXN 100100

typedef long long ll;

int n;
bool type[MAXN];
string s;

bool check(bool lier, bool eq, char c) {
  if (c == 'o') {
    return ((lier == false && eq) || (lier && eq == false));
  } else {
    return ((lier == false && eq == false) || (lier && eq));
  }
}
  

bool solve() {
  for (int i = 1; i < n - 1; i++) {
    int truth = type[i] ? 0 : 1;
    if (s[i] == 'x') truth = 1 - truth;
    type[i+1] = (truth) ? type[i-1] : !type[i-1];
  }
  if (!check(type[0], (type[n-1] == type[1]), s[0])) return false;
  if (!check(type[n-1], (type[n-2] == type[0]), s[n-1])) return false;
  return true;
}

void Print() {
  for (int i = 0; i < n; i++) {
    if (type[i]) cout << 'W';
    else cout << 'S';
  }
  cout << endl;
}
  
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> s;
  for (int i = 0; i < 4; i++) {
    type[0] = i & 1;
    type[1] = i & 2;
    if (solve()) {
      Print();
      return 0;
    }
  }
  cout << "-1" << endl;
  return 0;
}
