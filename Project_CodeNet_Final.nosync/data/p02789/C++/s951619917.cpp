#include <bits/stdc++.h>
#include <regex>
#include <iostream>
using namespace std;

#define _GLIBCXX_DEBUG

//vector<int> A(M), B(M);
//vector<vector<char>> answer(N, vector<char>(N, '-'));

int main() {
  int n, m;
  string ans;
  
  cin >> n >> m;
  
  if(n == m) ans = "Yes";
  else ans = "No";
  
  cout << ans << endl;
  return 0;
}