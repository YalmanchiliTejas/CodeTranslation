#include <bits/stdc++.h>
using namespace std;

#define each(i, c) for (auto& i : c)
#define mkp(a, b) make_pair(a, b)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
const ll MOD = 1e9+7;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << ": " << p.second << ")"; return os; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ", "; os << ")"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; each (i, m) os << i << ", "; os << "}"; return os; }

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