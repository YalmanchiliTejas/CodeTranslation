#include <iostream>
#include <string>

using namespace std;
int main(int argc, char const *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k;
  string s;
  cin >> n >> s >> k;
  int ans = 0;
  char tar = s[k-1];
  for (int i = 0; i < n; i++) {
    if (s[i] != tar) s[i]='*';
  }

  cout << s << "\n";
  return 0;
}