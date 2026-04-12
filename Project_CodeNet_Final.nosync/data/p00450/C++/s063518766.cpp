#include <iostream>
#include <functional>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

namespace _{struct _{_(){ // initialize
  cin.tie(0); ios::sync_with_stdio(false);
}}_;}
template <typename T, size_t size>
inline size_t len(const T (&)[size]) { return size; }
#define println(s) cout << s << '\n';
#define str to_string
#define rep(i, n) for (int i=0; i<int(n); i++)
#define all(c) (c).begin(), (c).end()

#define MAX_N 100001
#define WHITE 0
#define BLACK 1
int n;
int table[MAX_N];

// DEBUG
/*
void dump() {
  rep(i, n) {
    cout << (table[i]==WHITE?'.':table[i]==BLACK?'#':' ');
  }
  cout << '\n';
}
*/

int main() {
  while (true) {
    cin >> n;
    if (n == 0) break;
    rep(i, n) table[i] = -1;
    //
    rep(i, n) {
      // 0 -> ???, 1 -> ???
      int x; cin >> x;
      // ?\???°
      // if ((i+1) % 2 == 1)
      if (i % 2 == 0) table[i] = x;
      // ??¶??°
      else {
        // ????????¨????????????????????????
        if (table[i-1] == x) table[i] = x;
        else {
          int t = table[i-1]; // ????????????
          int j = i-1;
          // ??????????????¨??????(??£?¶?)??§???????????????????????????
          while (table[j] == t && j >= 0) {
            table[j] = x;
            j--;
          }
          table[i] = x;
        }
      }
      //dump();
    }
    int count = 0;
    rep(i, n) {
      if (table[i] == WHITE) count++;
    }
    cout << count << '\n';
  }
  return 0;
}