#include <iostream>
#include <string>
using namespace std;

int main() {
  int k;
  string s;
  cin >> k >> s >> k;
  char target = s[k - 1];
  for (char &c : s)
    if (c != target) c = '*';
  cout << s << endl;
  return 0;
}