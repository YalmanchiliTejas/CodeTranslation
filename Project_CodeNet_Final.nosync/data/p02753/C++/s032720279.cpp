#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  string S;
  cin >> S;
  if (S[0] != S[1] || S[1] != S[2])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
