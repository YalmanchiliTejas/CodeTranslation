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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;

int main()
{
  string right = "yuiophjklnm";
  string s;
  while(cin >> s) {
    if(s[0] == '#') return 0;
    int ans = 0;
    bool isright = right.find(s[0]) != string::npos;
    FOR(i,1,s.length()) {
      // ????????????
      if(right.find(s[i]) != string::npos) {
        if(!isright) ans++;
        isright = true;
      } else {
        if(isright) ans++;
        isright = false;
      }
    }
    cout << ans << endl;
  }
  return 0;
}