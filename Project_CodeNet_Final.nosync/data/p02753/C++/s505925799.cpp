#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  string S;
  cin >> S;
  if(S[0] != S[1] || S[1] != S[2] || S[0] != S[2]) puts("Yes");
  else puts("No");
}
