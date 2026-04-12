#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  char c;
  cin >> c;
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    cout << "vowel" << endl;
    return 0;
  }
  cout << "consonant" << endl;
  return 0;
}