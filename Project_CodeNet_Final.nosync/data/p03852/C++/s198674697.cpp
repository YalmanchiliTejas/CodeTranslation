/*  -*- coding: utf-8 -*-
 *
 * a.cc: A: 居合を終え、青い絵を覆う / UOIAUAI
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

  char &c = s[0];
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    puts("vowel");
  else
    puts("consonant");
  return 0;
}
