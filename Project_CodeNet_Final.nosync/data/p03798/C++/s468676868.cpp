#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main(int argc, const char * argv[]) {
  int n;
  string S;
  cin >> n >> S;
  
  string ans;
  vector<string> c = {"SS", "SW", "WS", "WW"};
  for (auto x : c) {
    ans = x;
    for (int i = 1; i < n; i++) {
      if (ans[i] == 'S') {
        if (S[i] == 'o') {
          ans += (ans[i - 1] == 'S' ? 'S' : 'W');
        } else {
          ans += (ans[i - 1] == 'S' ? 'W' : 'S');
        }
      } else {
        if (S[i] == 'x') {
          ans += (ans[i - 1] == 'S' ? 'S' : 'W');
        } else {
          ans += (ans[i - 1] == 'S' ? 'W' : 'S');
        }
      }
    }
    
    if (ans[0] == 'S') {
      if (S[0] == 'o') {
        if(ans[1] != ans[n - 1]) {
          continue;
        }
      } else {
        if(ans[1] == ans[n - 1]) {
          continue;
        }
      }
    } else {
      if (S[0] == 'x') {
        if(ans[1] != ans[n - 1]) {
          continue;
        }
      } else {
        if(ans[1] == ans[n - 1]) {
          continue;
        }
      }
    }
    if (ans[0] == ans[n]) {
      for (int i = 0; i < n; i++) {
        cout << ans[i];
      }
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
