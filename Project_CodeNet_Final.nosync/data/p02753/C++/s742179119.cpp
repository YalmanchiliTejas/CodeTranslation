#include <bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG

//vector<int> A(M), B(M);
//vector<vector<char>> answer(N, vector<char>(N, '-'));

int main() {
  string s;
  int a, b, c;
  
  cin >> s;
  
  if(s[0]==s[1] && s[1]==s[2])
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  
  return 0;
}