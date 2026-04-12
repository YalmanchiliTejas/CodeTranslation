#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  string S;
  cin >> S;
  bool is_ok = true;
  if (S[0] == S[1] && S[1] == S[2] && S[2] == S[0])
    is_ok = false;
  printYesNo(is_ok);
  return 0;
}