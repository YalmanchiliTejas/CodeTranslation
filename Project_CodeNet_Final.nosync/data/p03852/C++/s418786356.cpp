#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << (x) << endl
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> V;

int main() {
  char a;
  cin >> a;
  if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o') dump("vowel");
  else dump("consonant");
  return 0;
}
