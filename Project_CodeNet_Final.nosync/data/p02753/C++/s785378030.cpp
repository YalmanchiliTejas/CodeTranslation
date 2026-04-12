/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc158_a.cpp
 * time   : Sat May  2 19:39:16 2020
 * quest  : A - Station and Bus
 *********************************************/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  cout << ((s[0] != s[1] || s[1] != s[2]) ? "Yes\n" : "No\n");
  return 0;
}
