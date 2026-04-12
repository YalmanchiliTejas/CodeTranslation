#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

using namespace std;

int main() {
  string s;
  cin >> s;
  string ans = "Yes";
  if (s == "AAA" || s == "BBB") {
    ans = "No";
  }
  cout << ans << endl;
}
