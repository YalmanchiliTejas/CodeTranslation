#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

string beet(string a, string b, int x)
{
  string ret = "~";
  for(int i = x; i > 0; i--) { // x 個使う
    int64 rest = x - 1LL * i * (int) a.size();
    if(rest < 0) continue;
    if(rest % b.size() == 0) {
      ret = "";
      for(int j = 0; j < i; j++) ret += a;
      for(int j = 0; j < rest / b.size(); j++) ret += b;
      break;
    }
  }
  return (ret);
}

int main()
{
  int L;
  string S, T;

  cin >> L;
  cin >> S;
  cin >> T;
  cout << min(beet(S, T, L), beet(T, S, L)) << endl;
}