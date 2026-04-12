#include<iostream>
#include<string>
using namespace std;
int main() {
  int n, k;
  string s;
  cin >> n >> s >> k;
  string ans;
  for (char& c : s) {
    ans += (s[k - 1] == c ? string(1, c) : "*");
  }
  cout << ans << endl;
}
