#include<iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int k;
  cin >> k;
  char c = s[k-1];
  string ans = s;
  for(int i = 0; i < s.length(); i++) {
    ans[i] = ans[i] == c ? c : '*';
  }
  cout << ans << endl;
  return 0;
}
