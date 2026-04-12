#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string S;
  cin >> S;
  bool isExist = false;
  for (int i = 1; i < 3; i++)
    if (S[i - 1] != S[i])
      isExist = true;
  if (isExist)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
