#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;
const ll INFll = 1ll << 60;

int main() {
  char c;
  cin >> c;
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
  return 0;
}
