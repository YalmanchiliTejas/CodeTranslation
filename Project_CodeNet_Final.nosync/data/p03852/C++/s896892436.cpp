#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
  char c;
  cin >> c;
  set<char> st{'a', 'i', 'u', 'e', 'o'};
  cout << (st.count(c) ? "vowel" : "consonant") << endl;
  return 0;
}
