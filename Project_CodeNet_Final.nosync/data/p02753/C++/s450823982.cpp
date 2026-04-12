#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  string ans;
  if (S == "AAA" || S == "BBB")
    ans = "No";
  else
    ans = "Yes";
  cout << ans << endl;
}
