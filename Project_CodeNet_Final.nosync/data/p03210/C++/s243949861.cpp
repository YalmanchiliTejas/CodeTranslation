#include <iostream>

using namespace std;
int main(int argc, char const *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string ans = "NO";
  if (n == 3 || n == 5 || n == 7) {
    ans = "YES";
  }

  cout << ans << "\n";
  return 0;
}