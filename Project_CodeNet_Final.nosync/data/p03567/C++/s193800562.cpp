/*  -*- coding: utf-8 -*-
 *
 * a.cc: 
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>

using namespace std;

/* constant */

/* typedef */

/* global variables */

/* subroutines */

/* main */

int main() {
  string s;
  cin >> s;

  bool ok = false;
  for (int i = 0; ! ok && i < s.size() - 1; i++)
    ok = (s[i] == 'A' && s[i + 1] == 'C');

  if (ok) puts("Yes");
  else puts("No");
  return 0;
}
