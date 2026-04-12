#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  char c;
  cin >> c;

  cout << ((c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
               ? "vowel"
               : "consonant")
       << endl;
  return 0;
}
