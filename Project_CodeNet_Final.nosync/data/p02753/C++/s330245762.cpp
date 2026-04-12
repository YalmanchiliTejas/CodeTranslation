#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
ll Mod = 998244353;
int main() {
  string S;
  cin >> S;
  if (S[0] == S[1] && S[1] == S[2]) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}