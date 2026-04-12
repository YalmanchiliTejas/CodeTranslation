#include <bits/stdc++.h>
 
using namespace std;
 
int dp[105][4][2];
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);                                  
  int n, m;
  cin >> n >> m;
  if (n == m) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}