#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main () {
  string S;
  cin >> S;
  if (S[0] == S[1] && S[1] == S[2]) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }
  return 0;
}