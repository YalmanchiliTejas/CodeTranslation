#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  char c;
  cin >> c;
  string ans = "consonant";

  if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
    ans = "vowel";
  cout << ans << endl;
  return 0;
}