#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  char s[n];
  cin >> s;
  int k;
  cin >> k;
  for (int i=0; i<n; i++) {
    if ((i != k-1) && (s[i] != s[k-1])) {
      s[i] = '*';
    }
  }
  cout << s << endl;
}