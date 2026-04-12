#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

string S;

int dfs(int idx, int num = 0, int sz = 0) {
  if(idx == S.size()) return sz == 4 && num == 0;
  int ret = 0;
  if(S[idx] == '0') {
    int nxt = num * 10;
    if(num == 0) {
      ret += dfs(idx + 1, 0, sz + 1);
    } else {
      ret += dfs(idx + 1, nxt, sz);
      if(0 <= nxt && nxt < 256) ret += dfs(idx + 1, 0, sz + 1);
    }
  } else {
    int nxt = num * 10 + S[idx] - '0';
    ret += dfs(idx + 1, nxt, sz);
    if(0 <= nxt && nxt < 256) ret += dfs(idx + 1, 0, sz + 1);
  }
  return ret;
}

int main() {

  cin >> S;
  cout << dfs(0) << endl;


}
