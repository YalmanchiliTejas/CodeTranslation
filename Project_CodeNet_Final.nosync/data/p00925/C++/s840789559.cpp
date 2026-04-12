#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  string s; cin >> s;
  bool used[s.length()]; CLR(used);
  ll ans1 = 0;
  ll cal = s[0] - '0';
  // method 1
  bool plus = false;
  for(int i = 1; i < s.length(); i += 2) {
    if(s[i] == '*') {
      cal *= s[i+1] - '0';
      used[i-1] = used[i+1] = true;
      if(i == s.length() - 2) {
        ans1 += cal;
      }
      plus = true;
    } else if(plus){
      ans1 += cal;
      cal = s[i+1] - '0';
      plus = false;
    } else {
      cal = s[i+1] - '0';
    }
  }
  for(int i = 0; i < s.length(); i += 2) {
    if(!used[i]) ans1 += s[i] - '0';
  }
  // method 2
  ll ans2 = s[0] - '0';
  for(int i = 1; i < s.length(); i += 2) {
    if(s[i] == '*') {
      ans2 *= s[i+1] - '0';
    } else {
      ans2 += s[i+1] - '0';
    }
  }
  //cout << ans1 << " " << endl;
  ll x; cin >> x;
  if(ans1 == x && ans2 == x) {
    puts("U");
  } else if(ans1 == x) {
    puts("M");
  } else if(ans2 == x) {
    puts("L");
  } else {
    puts("I");
  }
  return 0;
}