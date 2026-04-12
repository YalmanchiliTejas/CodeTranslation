#include<iostream>
using namespace std;
int main() {
  int n, k; string s;
  cin >> n >> s >> k;
  char tmp = s[k - 1];
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != tmp) s[i] = '*';
  }
  cout << s << endl;
}