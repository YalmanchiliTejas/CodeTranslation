#include <bits/stdc++.h>
using namespace std;

string s;

long long solve();
bool ch(int x, int y);

int main() {
  cin >> s;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long cnt = 0;
  for(int i = 0; i < s.size() - 2; ++i)
    for(int j = i + 1; j < s.size() - 1; ++j)
      for(int k = j + 1; k < s.size(); ++k) {
        if(ch(0, i) && ch(i + 1, j) && ch(j + 1, k) &&
           ch(k + 1, s.size() - 1))
          ++cnt;
      }
  return cnt;
}

bool ch(int x, int y) {
  if(x > y) return 0;
  if(x != y && s[x] == '0') return 0;
  long long now = 0;
  for(int i = x; i <= y; ++i) {
    now *= 10;
    now += s[i] - '0';
  }
  return now <= 255;
}
